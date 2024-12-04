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

int main() {
  int ac = 0;
  int wa = 100;

  while(1 <= wa - ac){
    // 中間を求める
    int mid = (wa + ac) / 2;

    // 求めた中間で計算した結果
    int v = 0;

    // 条件を満たす場合は、acと中間を入れ替える
    // 条件を満たさない場合は、waと中間を入れ替える
    if(v < N) {
      ac = mid;
    } else {
      wa = mid;
    }
  }

  // acが条件の境目になる。
  cout << ac << endl;
  return 0;
}
