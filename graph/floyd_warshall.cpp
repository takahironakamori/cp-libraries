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

int main() {
  // N は頂点数、M は辺の数
  ll N, M;
  cin >> N >> M;

  // 要素数はN + 1
  // あらかじめ INF を入れておく
  vector<vector<ll>> g(101, vector<ll>(101));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i != j) {
        g[i][j] = INF;
      }
    }
  }

  // 頂点 u から頂点 v までの重みが c
  int u, v;
  ll c;
  for(int i = 0; i < M; i++) {
    cin >> u >> v >> c;
    g[u][v] = c;
  }

  // ワーシャルフロイドで全点間の距離を計算する
  for(int k = 0; k < N; k++) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  ll ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      ans += g[i][j];
    }
  }

  cout << ans << endl;
  return 0;
}
