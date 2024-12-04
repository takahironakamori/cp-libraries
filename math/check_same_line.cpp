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

// p1, p2 を結ぶ直線の上に p3 があれば true, なければ false
bool f(P p1, P p2, P p3) {
  ll v1 = (p2.first - p1.first) * (p3.second - p1.second);
  ll v2 = (p2.second - p1.second) * (p3.first - p1.first);
  return (v1 == v2);
}

int main() {
  P p1 = make_pair(0, 0);
  P p2 = make_pair(1, 0);
  P p3 = make_pair(1, 1);
  bool flg = f(p1, p2, p3);
  return 0;
}
