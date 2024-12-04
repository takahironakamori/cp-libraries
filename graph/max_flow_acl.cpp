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
  int V, E;
  cin >> V >> E;

  mf_graph<ll> flow(V);
  rep(i, E) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    u--;
    v--;
    flow.add_edge(u, v, c);
  }

  ll ans = flow.flow(0, V - 1);
  cout << ans << endl;
  return 0;
}
