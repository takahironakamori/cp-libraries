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

// * 2^{-i} は mint(2).inv().pow(i)

int main() {
  mint ans = 0;

  ans = mint(2).inv().pow(2);

  cout << ans.val() << endl;
  return 0;
}
