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
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N+1);
  rep(i, N) { cin >> A[i+1]; }
  vector<int> X(N+1);
  vector<int> Y(N+1);
  rep(i, Q) { cin >> X[i+1] >> Y[i+1]; }

  // 前計算
  // 2^0, 2^1, 2^2, 2^3, ... 2^30 の時の場所を前計算する
  vector<vector<int>> dp(31, vector<int>(N+1));
  for(int i = 1; i <= N; ++i) {
    dp[0][i] = A[i];
  }
  for(int i = 1; i <= 30; ++i) {
    for(int j = 1; j <= N; ++j) {
      dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
  }

  // クエリの処理
  // 例 13 -> 1101 (= 2^3 + 2^2 + 2^0) と考えて計算する
  for (int i = 1; i <= Q; ++i) {
    int current = X[i];
    for (int j = 30; 0 <= j; --j) {
      if ((Y[i] / (1 << j)) % 2 != 0) {
        current = dp[j][current];
      }
    }
    cout << current << endl;
  }
  return 0;
}
