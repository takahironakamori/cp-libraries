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
  int N, M;
  cin >> N >> M;

  vector<pair<ll, P>> edges(M);

  dsu uf(N);

  rep(i, M) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    edges[i] = make_pair(c, make_pair(u, v));
  }

  sort(edges.begin(), edges.end());

  ll ans = 0;

  rep(i, M) {
    ll c = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    if(!uf.same(u, v)) {
      uf.merge(u, v);
      ans += c;
    }
  }

  cout << ans << endl;
  return 0;
}
