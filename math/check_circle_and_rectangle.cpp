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

// 距離を計算する
int dist(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
  int x1, y1, r, x2, y2, x3, y3;
  cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;

  // 赤
  string ans1 = "YES";
  // 青
  string ans2 = "YES";

  /*
   * 円が四角に完全に入ってしまう(ans1 = NO)条件
   * x2 <= x1 - r &&
   * r + x1 <= x3 &&
   * y2 <= y1 - r &&
   * r + y1 <= y3
   */
  if(x2 <= x1 - r && r + x1 <= x3 && y2 <= y1 - r && r + y1 <= y3) {
    ans1 = "NO";
  }

  /*
   * 四角が円に完全に入ってしまう(ans2 = NO)条件
   * dist(x1,y1,x2,y2) <= r * r &&
   * dist(x1,y1,x3,y3) <= r * r &&
   * dist(x1,y1,x2,y3) <= r * r &&
   * dist(x1,y1,x3,y2) <= r * r
   */
  int rr = r * r;
  if(dist(x1, y1, x2, y2) <= rr && dist(x1, y1, x3, y3) <= rr &&
     dist(x1, y1, x2, y3) <= rr && dist(x1, y1, x3, y2) <= rr) {
    ans2 = "NO";
  }

  cout << ans1 << endl;
  cout << ans2 << endl;
  return 0;
}
