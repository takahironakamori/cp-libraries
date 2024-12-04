#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
// using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

int N;
vector<vector<int>> graph;
vector<bool> visited;
set<int> ans;

vector<int> topological_sort(vector<vector<int>> graph) {
	int n = graph.size();
	vector<int> indegree(n);
	for (int i = 0; i < n; i++) for (int j : graph[i]) indegree[j]++;
	vector<int> res;
	queue<int> que;
	for (int i = 0; i < n; i++) if (indegree[i] == 0) que.push(i);
	while (!que.empty()) {
		int ver = que.front(); que.pop();
		res.push_back(ver);
		for (int i : graph[ver]) {
			indegree[i]--;
			if (indegree[i] == 0) que.push(i);
		}
	}
	return res;
}

void dfs(int current) {
  if (visited[current]) {
    return;
  }
  visited[current] = true;
  if (current != 0) {
    ans.insert(current);
  }
  int n = graph[current].size();
  rep(i, n) {
    int nxt = graph[current][i];
    dfs(nxt);
  }
}

int main() {
  cin >> N;
  graph.resize(N);
  visited.resize(N);
  rep(i, N) {
    int C;
    cin >> C;
    int A = i;
    rep(j, C) {
      int B;
      cin >> B;
      B--;
      graph[A].push_back(B);
    }
  }

  dfs(0);

  vector<int> t = topological_sort(graph);
  vector<int> order(N);
  rep(i, N) {
    order[t[i]] = i;
  }
  vector<int> ans_;
  for(auto i:ans){
    ans_.push_back(i);
  }
  sort(ans_.begin(), ans_.end(), [&](int x, int y) {return order[x] > order[y];});

  rep(i, (int)ans_.size()) {
    cout << ans_[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}
