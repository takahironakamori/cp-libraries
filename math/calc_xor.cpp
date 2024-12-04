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

// 0 から v までの XOR を計算する
ll calcXOR(ll v) {
  if(v == 0) {
    return 0;
  }
  v++;
  ll res = 0;
  for(int i = 0; i < 50; i++) {
    // 1 の個数を計算するために、周期を求める
    ll loop = (1LL << (i + 1));

    // 1 の個数 = ループした回数 × 1 が出てくる回数
    // 0(000) から 4(100) までの場合下 2 桁までを数える
    ll count = (v / loop) * (loop / 2);

    // 0(000) から 4(100) までの場合、 3 桁目で 1 が出てくる回数を加える
    count += max(0LL, (v % loop) - (loop / 2));

    // その桁が 奇数 だったら答えに加える
    if(count % 2 == 1) {
      res += 1LL << i;
    }
  }

  return res;
}

int main() {
  ll A;
  cin >> A;

  // 0 から A までの XOR
  ll ans = calcXOR(A);

  cout << ans << endl;
  return 0;
}
