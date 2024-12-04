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

// 2次元いもす法
vector<vector<ll>> imos2D(ll H, ll W, vector<ll> A, vector<ll> B, vector<ll> C, vector<ll> D) {
  int s = A.size();
  vector<vector<ll>> v(H + 2, vector<ll>(W + 2));
  rep(i, s) {
    v[A[i]][B[i]]++;
    v[A[i]][D[i] + 1]--;
    v[C[i] + 1][B[i]]--;
    v[C[i] + 1][D[i] + 1]++;
  }
  vector<vector<ll>> sum(H+1, vector<ll>(W+1));
  for(int i = 1; i <= H; ++i) {
    for(int j = 1; j <= W; ++j) {
      if (j == 1) {
        sum[i][j] = v[i][j];
      } else {
        sum[i][j] = sum[i][j - 1] + v[i][j];
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
  ll H, W, N;
  cin >> H >> W >> N;

  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(N);
  vector<ll> D(N);
  rep(i, N) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  vector<vector<ll>> ans = imos2D(H, W, A, B, C, D);

  rep(i, H) {
    rep(j, W) {
      cout << ans[i + 1][j + 1] << " ";
    }
    cout << endl;
  }
  return 0;
}
