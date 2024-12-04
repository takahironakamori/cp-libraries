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

ll calcCross(ll ax, ll ay, ll bx, ll by) {
  // ベクトル(ax, ay)と(bx, by)の外積の大きさ
  return ax * by - ay * bx;
}

// 線分ab と線分cd で重なっている区間があるか否かを返す
// P<ll,ll>
bool chackLapping(P a, P b, P c, P d) {
  // a < b にする
  if(b < a) {
    swap(a, b);
  }
  // c < d にする
  if(d < c) {
    swap(c, d);
  }
  // 区間が重なるかを判定
  if(max(a, c) <= min(b, d)) {
    return true;
  } else {
    return false;
  }
}

// 線分1(p1(x1,y1) と p2(x2,y2) を結ぶ) と
// 線分2(p2(x3,y3) と p4(x4,y4) を結ぶ) が
// 交差しているか否かをチェックする
// ※要 calcCross, chackLapping
bool checkCross(P p1, P p2, P p3, P p4) {
  ll x1 = p1.first;
  ll y1 = p1.second;
  ll x2 = p2.first;
  ll y2 = p2.second;
  ll x3 = p3.first;
  ll y3 = p3.second;
  ll x4 = p4.first;
  ll y4 = p4.second;

  ll ans1 = calcCross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
  ll ans2 = calcCross(x2 - x1, y2 - y1, x4 - x1, y4 - y1);
  ll ans3 = calcCross(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
  ll ans4 = calcCross(x4 - x3, y4 - y3, x2 - x3, y2 - y3);

  // 全部一直線上にある場合、重なっている否かを判定
  if(ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 == 0) {
    if(chackLapping(p1, p2, p3, p4)) {
      return true;
    } else {
      return false;
    }
  }

  bool ab = false;
  bool cd = false;
  if(0 <= ans1 && ans2 <= 0) {
    ab = true;
  }
  if(ans1 <= 0 && 0 <= ans2) {
    ab = true;
  }
  if(0 <= ans3 && ans4 <= 0) {
    cd = true;
  }
  if(ans3 <= 0 && 0 <= ans4) {
    cd = true;
  }

  if(ab && cd) {
    return true;
  } else {
    return false;
  }
}

int main() {
  ll x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

  P p1 = make_pair(x1, y1);
  P p2 = make_pair(x2, y2);
  P p3 = make_pair(x3, y3);
  P p4 = make_pair(x4, y4);

  bool ans = checkCross(p1, p2, p3, p4);

  if(ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}