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
  int y, x;
  cin >> y >> x;

  // 点（a, b)と原点の角度（ラジアン）を計る
  double theta = atan2(y, x);

  // ラジアンを度に変える
  theta = theta * 180 / M_PI;

  printf("%.12f", theta);
  cout << endl;
  return 0;
}