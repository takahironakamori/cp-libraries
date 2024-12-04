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

// (H + 1) * (W + 1) の2次元累積和を返す
vector<vector<ll>> create2DCumulativeSum(int H, int W, vector<vector<ll>> &v) {
  vector<vector<ll>> sum(H+1, vector<ll>(W+1));
  for(int i = 1; i <= H; ++i) {
    for(int j = 1; j <= W; ++j) {
      if (j == 1) {
        sum[i][j] = v[i - 1][j - 1];
      } else {
        sum[i][j] = sum[i][j - 1] + v[i - 1][j - 1];
      }
    }
  }
  for(int j = 1; j <= W; ++j) {
    for(int i = 1; i <= H; ++i) {
      if (i == 1) {
        continue;
      } else {
        sum[i][j] = sum[i - 1][j] + sum[i][j];
      }
    }
  }
  return sum;
}

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<ll>> maze(H, vector<ll>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> maze[i][j];
    }
  }

  int Q;
  cin >> Q;
  vector<int> A(Q);
  vector<int> B(Q);
  vector<int> C(Q);
  vector<int> D(Q);
  rep(i, Q) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  vector<vector<ll>> sum = create2DCumulativeSum(H, W, maze);

  /*
  for(int i = 0; i <= H; ++i) {
    for(int j = 0; j <= W; ++j) {
      cout << sum[i][j] << " ";
    }
    cout << endl;
  }
  */

  rep(i, Q) {
    ll ans = sum[C[i]][D[i]] + sum[A[i]-1][B[i]-1] - sum[C[i]][B[i]-1] - sum[A[i]-1][D[i]];
    cout << ans << endl;
  }

  return 0;
}
