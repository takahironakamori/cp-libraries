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

// ax + by = g となる x, y, g を返す
tuple<ll,ll,ll> extgcd(ll a, ll b) {
  if (b == 0) {
    return {a, 1, 0};
  }
  ll g, x, y;
  tie(g, x, y) = extgcd(b, a%b);
  return {g, y, x-a/b*y};
}

ll expantedEuclid(ll a, ll b, ll &x, ll &y) {
  ll d;
  if (b == 0) {
    d = a;
    x = 1;
    y = 0;
  } else {
    d = expantedEuclid(b, a%b, y, x);
    y -= a / b * x;
  }
  return d;
}

int main() {
  ll a, b, x, y;
  cin >> a >> b;

  expantedEuclid(a, b, x, y);

  cout << x << " " << y << endl;
  return 0;
}
