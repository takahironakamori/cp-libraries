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

// 制限時間(単位:秒)
double TIME_LIMIT = 1.9;

// タイマースタート
auto TIMER_START = clock();


/**
 *【案00】〇〇にする
 * Seed000 : xxxxxxxx
 */
void solve00() {
  for(int simulate_cnt = 0;; simulate_cnt++) {
    double p = (double)(clock() - TIMER_START) / CLOCKS_PER_SEC / TIME_LIMIT;
    if(1.0 <= p) {
      cout << "Time Limit :" << simulate_cnt << endl;
      break;
    }

    // ここに処理
  }
}


int main() {

  //【案00】〇〇にする
  solve00();
  
  return 0;
}
