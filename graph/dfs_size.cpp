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

int dfs(int current, int prev) {
  int res = 1;
  for(auto i: graph[current]) {
    if (i == prev) {
      continue;
    }
    res += dfs(i, current);
  }
  return res;
}

int main() {
  cin >> N;
  graph.resize(N);

  vector<int> start;
  rep(i, N-1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // 0を根とする連結成分の数を数える
  int cnt = dfs(0, -1);

  cout << cnt << endl;
  
  return 0;
}
