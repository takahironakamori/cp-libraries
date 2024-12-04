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
vector<int> ans;

void dfs(int current, int previous) {
  ans.push_back(current);
  int n = graph[current].size();
  rep(i, n) {
    int nxt = graph[current][i];
    if (nxt != previous) {
      dfs(nxt, current);
      ans.push_back(current);
    }
  }
}

int main() {
  cin >> N;

  graph.resize(N);

  rep(i, N - 1) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }

  rep(i, N) {
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(0, -1);

  int n = ans.size();
  rep(i, n) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}
