#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

int main() {
  int N;
  cin >> N;

  vector<mint> ans(N + 1);
  ans[1] = 1;
  ans[2] = 1;
  for(int i = 3; i <= N; ++i) {
    ans[i] = ans[i - 1] + ans[i - 2];
  }

  cout << ans[N].val() << endl;
  return 0;
}
