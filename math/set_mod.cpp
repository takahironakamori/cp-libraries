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

using mint = modint;

int main() {
  int N,;
  cin >> N;

  // 10^9 で割った余りを計算する
  mint::set_mod(1000000000);

  mint ans = N;

  cout << ans.val() << endl;
  return 0;
}