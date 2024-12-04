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
  ll N;
  cin >> N;

  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());
  
  ll r = 0;
  for(ll l = 0; l < N; ++l) {
    while(r < N && 条件)) {
      // 満たす場合の処理

      r++;
    }
    // 満たさなくなった場合の処理
  }
  return 0;
}
