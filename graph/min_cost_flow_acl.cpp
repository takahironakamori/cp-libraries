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
  int V, E, F;
  cin >> V >> E >> F;

  mcf_graph<ll, ll> mincost_flow(V);

  rep(i, E) {
    int u, v, capacity, cost;
    cin >> u >> v >> capacity >> cost;
    u--;
    v--;
    mincost_flow.add_edge(u, v, capacity, cost);
  }

  cout << mincost_flow.flow(0, V - 1, F).second << endl;
  return 0;
}
