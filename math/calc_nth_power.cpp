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

// 2 の n 乗(mod 1000000007)を計算する
mint calc2toTheNthPower(ll n) {
  if(n == 0) {
    return 1;
  }
  mint x = calc2toTheNthPower(n / 2);
  x *= x;
  if(n % 2 == 1) {
    x *= 2;
  }
  return x;
}

int main() {
  ll N;
  cin >> N;

  mint ans = calc2toTheNthPower(N);
  cout << ans.val() << endl;

  return 0;
}
