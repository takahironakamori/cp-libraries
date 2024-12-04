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
  ll N;
  cin >> N;

  vector<ll> v(N);
  rep(i, N) {
  cin >> v[i];
    v[i]--;
  }

  ll ans = 0;

  fenwick_tree<ll> ft(N);

  for (int i = 0; i < N; ++i) {
    ans += (ll)i - ft.sum(0, v[i]);
    ft.add(v[i], 1);
  }

  cout << ans << endl;
  return 0;
}
