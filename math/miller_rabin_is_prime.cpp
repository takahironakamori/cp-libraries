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

template<class T> T pow_mod(T A, T N, T M) {
  T res = 1 % M;
  A %= M;
  while (N) {
    if (N & 1) {
      res = (res * A) % M;
    }
    A = (A * A) % M;
    N >>= 1;
  }
  return res;
}

bool is_prime(ll N) {
  if (N <= 1) {
    return false;
  }
  if (N == 2) {
    return true;
  }
  if (N % 2 == 0) {
    return false;
  }
  vector<ll> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  ll s = 0;
  ll d = N - 1;
  while(d % 2 == 0) {
    ++s;
    d >>= 1;
  }
  for(auto a: A) {
    if (a % N == 0) {
      return true;
    }
    ll t;
    ll x = pow_mod<__int128_t>(a, d, N);
    if (x != 1) {
      for (t = 0; t < s; ++t) {
        if (x == N - 1) {
          break;
        }
        x = __int128_t(x) * x % N;
      }
      if (t == s) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int N;
  cin >> N;

  rep(i, N) {
    ll A;
    cin >> A;
    if (is_prime(A)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
