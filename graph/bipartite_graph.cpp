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

int N, M;
vector<vector<int>> graph;
vector<int> color;
bool isBipartite = true;

// p:現在位置、
// c:あるべき色(0 or 1)
// 二部グラフの場合は、isBipartite = true
// 二部グラフではない場合は、isBipartite = false
void dfs(int p, int c) {
  color[p] = c;
  for(auto i: graph[p]) {
    if (color[i] == -1) {
      dfs(i, 1 - c);
    } else if (color[p] == color[i]) {
      isBipartite = false;
    }
  }
}

int main() {
  cin >> N >> M;

  graph.resize(N);
  color.resize(N, -1);

  vector<int> u(M);
  vector<int> v(M);

  rep(i, M) {
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
    graph[u[i]].push_back(v[i]);
    graph[v[i]].push_back(u[i]);
  }

  rep(i, N) {
    if (color[i] == -1) {
      dfs(i, 0);
    }
  }

  if(isBipartite) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
