#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

// aの0乗からaのb乗までの合計(mod 1000000007)を計算する
mint calcSumOfAToTheNPower(ll a, ll b) {
  mint result = mint(a).pow(b + 1) - 1;
  result /= (a - 1);
  return result;
}

int main() {
  ll N;
  cin >> N;

  mint ans = calcSumOfAToTheNPower(4, N);
  cout << ans.val() << endl;
  return 0;
}
