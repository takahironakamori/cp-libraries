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

ll my_pow(ll a, ll b) {
  ll res = 1;
  while(b) {
    if(b & 1) {
      res *= a;
    }
    a *= a;
    b >>= 1;
  }
  return res;
}

int main() {
  ll a, b;
  cin >> a >> b;

  ll res = my_pow(a, b);
  cout << res << endl;
  return 0;
}
