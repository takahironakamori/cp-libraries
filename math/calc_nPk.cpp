#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
using mint = modint1000000007;
const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

// n_C_k を計算する
struct combination {
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1) {
    assert(n < mod);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
      fact[i] = fact[i - 1] * i;
    }
    ifact[n] = fact[n].inv();
    for(int i = n; i >= 1; i--) {
      ifact[i - 1] = ifact[i] * i;
    }
  }
  mint operator()(int n, int k) {
    if(k < 0 || k > n) {
      return 0;
    } else {
      return fact[n] * ifact[k] * ifact[n - k];
    }
  }
};

combination c(100010);

// n_P_k を計算する
mint permutation(int n, int k) {
  if(n < 0) {
    return 0;
  }
  // n_P_k = n_C_k * k!
  mint result = c(n, k);
  result *= c.fact[k];
  return result;
}

int main() {
  int N, K;
  cin >> N >> K;

  mint ans = permutation(N, K);

  cout << ans.val() << endl;
  return 0;
}
