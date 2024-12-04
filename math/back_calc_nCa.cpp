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

/*
 (r,c) = {c + r}_C_c
 (r,c+1) = {c + r + 1}_C_c
 (r+1,c) = {c + r + 1}_C_{c+1}
 k = r + c とすると、
 k_C_c, {k+1}_C_c, {k+1}_C_{c+1} が与えられるので、
 k-c, cを求めよという問題になる。
*/

int main() {
  ll A, B, C;
  cin >> A >> B >> C;

  mint c1 = (B * C) - (A * B);
  mint c2 = (A * C) - (B * C) + (A * B);
  mint c = c1 / c2;

  mint r1 = (B * C) - (A * C);
  mint r2 = (A * B) - (B * C) + (A * C);
  mint r = r1 / r2;

  cout << r.val() << " " << c.val() << endl;
  return 0;
}
