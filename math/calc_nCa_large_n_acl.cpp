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

// n_C_a を計算する(n が大きくて k が小さい場合)
mint calcnCaLargeN(int n, int a) {
  mint x = 1;
  mint y = 1;
  for(int i = 0; i < a; i++) {
    x *= n - i;
    y *= i + 1;
  }
  return x / y;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  mint ans = calcnCaLargeN(n, a);

  cout << ans.val() << endl;
  return 0;
}
