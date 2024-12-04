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

// 181718
// keta  | 10^5 10^4 10^3 10^2 10^1 10^0
// S     |    1    8    1    7    1    8
// amari |    8  958 1718  718   18    8

// amari が同じ値の範囲（10^5 から 10^1 まで）を抜き出した値は
// 2019 で割り切れる

// cnt[0] 〜 [2018] ... 余りになった回数
// 2回目から答えに1加えていく

int main() {
  string S;
  cin >> S;
  int n = S.size();

  ll mod = 2019;

  ll ans = 0;
  ll amari = 0;
  ll keta = 1;
  vector<int> cnt(mod);
  cnt[0]++;

  for(int i = n - 1; 0 <= i; --i) {
    amari += (S[i] - '0') * keta;
    amari %= mod;
    ans += cnt[amari];
    cnt[amari]++;
    keta = (keta * 10) % mod;
  }

  cout << ans << endl;

  return 0;
}
