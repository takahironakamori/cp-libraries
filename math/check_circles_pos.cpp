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

double dist(P p1, P p2) {
  double distX = p1.first - p2.first;
  double distY = p1.second - p2.second;
  double result = sqrt(distX * distX + distY * distY);
  return result;
}


int main() {
  double x1, y1, r1;
  double x2, y2, r2;
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;

  P p1 = make_pair(x1, y1);
  P p2 = make_pair(x2, y2);
  double d = dist(p1, p2);

  string ans = "";

  if(d < abs(r1 - r2)) {
    // 円内部に入っている
    ans = "1";
  } else if(d == abs(r1 - r2)) {
    // 円内部に入っていて接している
    ans = "2";
  } else if(d < r1 + r2) {
    // 円が重なっている
    ans = "3";
  } else if(d == r1 + r2) {
    // 円外部で接している
    ans = "4";
  } else {
    // 円は離れている
    ans = "5";
  }

  cout << ans << endl;
  return 0;
}
