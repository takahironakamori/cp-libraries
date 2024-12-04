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

// res[i][c] := 下から i 桁目が j となるような N 以下の整数の個数を返す
vector<vector<ll>> cnt_number(ll N) {
  // 桁数を数える
  string s = to_string(N);
  int n = (int) s.size();

  // 10 の n 乗
  vector<ll> p(n + 1);
  for (int i = 0; i < n + 1; i++) {
    if (i == 0) {
      p[0] = 1;
    } else {
      p[i] = 10 * p[i - 1];
    }
  }

  vector<vector<ll>> res(n, vector<ll>(10));
  for (int i = 0; i < n; i++) {
    int d = (int) s[n - i - 1] - '0';
    for (int j = 0; j < 10; j++) {
      if (j < d) {
        res[i][j] = (N / p[i + 1]) * p[i] + p[i];
      } else if (j == d) {
        res[i][j] = (N / p[i + 1]) * p[i] + (N % p[i]) + 1;
      } else {
        res[i][j] = (N / p[i + 1]) * p[i];
      }
    }
  }
  return res;
}

int main() {
  ll N;
  cin >> N;

  ll ans = 0;
  auto res = cnt_number(N);
  for (auto num:res) {
    for (int i = 0; i < 10; i++) {
      ans += num[i] * i;
    }
  }
  cout << ans << endl;
  return 0;
}
