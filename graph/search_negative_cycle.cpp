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

// ベルマンフォード法で最短経路を見つけることができれば、負閉路は無いことになる。

// 頂点fromから頂点toへの重みcost
struct edge {
  int from, to, cost;
};

int N, M;
int INF;
vector<edge> es;
vector<vector<int>> dist;
string ans;

void bellmanFord (int n, int s) {
  for (int i = 1; i <= n-1; i++) {
    dist[i] = dist[i - 1];
    for(int j = 0; j < M; ++j) {
      edge e = es[j];
      dist[i][e.to] = min(dist[i][e.to], dist[i][e.from] + e.cost);
    }
    if (dist[i] == dist[i-1]) {
      ans = "No";
      return;
    }
  }
  return;
}


int main() {
  cin >> N >> M;

  INF = 1000000000;

  es.resize(M);
  dist.resize(N, vector<int>(N, INF));

  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge e;
    e.from = u;
    e.to = v;
    e.cost = w;
    es[i] = e;
  }

  dist[0][0] = 0;

  ans = "Yes";

  bellmanFord(N, 0);

  cout << ans << endl;
  return 0;
}
