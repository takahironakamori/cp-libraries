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

// 点 p1 と点 p2 の距離を返す
double calc_dist(P p1, P p2) {
  double distX = p1.first - p2.first;
  double distY = p1.second - p2.second;
  double result = sqrt(distX * distX + distY * distY);
  return result;
}

int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  P p1 = make_pair(x1, y1);
  P p2 = make_pair(x2, y2);

  double ans = calc_dist(p1, p2);

  printf("%.16f", ans);
  printf("\n");
  return 0;
}
