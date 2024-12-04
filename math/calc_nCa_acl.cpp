#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
using mint = modint1000000007;
const ll mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

/*
上にH-1回、右にW-1回移動する組み合わせの個数を求める。
(H+W-2)回からH-1回移動する方法を求めればいい。
{H+W-2}_C_{H-1} を求める
（(H+W-2)!/(H-1)!(W-1)!を求める）
*/

// n_C_a を計算する(mint)
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

int main() {
  ll W, H;
  cin >> W >> H;

  combination c(W + H + 5);
  mint ans = c(W + H - 2, H - 1);

  cout << ans.val() << endl;
  return 0;
}
