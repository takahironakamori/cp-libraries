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

// n_C_a を計算する
ll calcnCa(ll n, int a) {
  ll x = 1;
  ll y = 1;
  for(int i = 0; i < a; i++) {
    x = x * (n - i);
    x /= (i + 1);
  }
  return x;
}

int main() {
  ll N, K;
  cin >> N >> K;

  ll ans = calcnCa(N, K);

  cout << ans << endl;
  return 0;
}
