#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, ll>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
// using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

int main() {
  ll x;
  cin >> x;

  // すべてのビットを反転する
  ll x1 = ~x;

  // 左に 1 ビット論理シフトする
  ll x2 = x << 1;

  // 右に 1 ビット論理シフトする
  ll x3 = x >> 1;

  // 32 桁のビット列を出力する
  cout << bitset<32>(x) << endl;
  cout << bitset<32>(x1) << endl;
  cout << bitset<32>(x2) << endl;
  cout << bitset<32>(x3) << endl;
  return 0;
}
