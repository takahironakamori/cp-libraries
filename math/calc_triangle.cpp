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

// p1 〜 p3（x,y）の三角形の面積を計算する
ll calcTriangle(P p1, P p2, P p3) {
  ll x1_3 = p1.first - p3.first;
  ll y2_3 = p2.second - p3.second;
  ll x2_3 = p2.first - p3.first;
  ll y1_3 = p1.second - p3.second;
  ll res = abs(x1_3 * y2_3 - x2_3 * y1_3);
  return res;
}

int main() {
  ll x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  P p1 = make_pair(x1, y1);
  P p2 = make_pair(x2, y2);
  P p3 = make_pair(x3, y3);

  ll ans = calcTriangle(p1, p2, p3);

  cout << ans << endl;
  return 0;
}
