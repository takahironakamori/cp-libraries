#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, string>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using mint = modint998244353;
// using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

// BIT（最大値）
struct BIT {
  vector<ll> data;
  int n;

  BIT(int size) : n(size) {
    data.assign(n + 1, 0);
  }

  void update(int idx, ll val) {
    while(idx <= n) {
      data[idx] = max(data[idx], val);
      idx += idx & -idx;
    }
  }

  ll query(int idx) {
    ll res = 0;
    while(0 < idx) {
      res = max(res, data[idx]);
      idx -= idx & -idx;
    }
    return res;
  }
};

int main() {
  int N;
  cin >> N;
  vector<ll> h(N);
  rep(i, N) {
    cin >> h[i];
  }
  vector<ll> a(N);
  rep(i, N) {
    cin >> a[i];
  }

  BIT bit(N);
  
  ll ans = 0;
  for(int i = 0; i < N; i++) {
    // 高さ h[i]-1 以下の最大値を取得
    ll best = bit.query(h[i] - 1);
    
    // 現在の dp[i] を計算
    ll dp = best + a[i];

    // 結果を更新
    ans = max(ans, dp);

    // BIT を更新
    bit.update(h[i], dp);
  }

  cout << ans << endl;
  return 0;
}