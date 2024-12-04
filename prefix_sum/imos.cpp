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

// いもす法
vector<ll> imos(int N, vector<ll> L, vector<ll> R) {
  int s = L.size();
  vector<ll> sum(N + 2);
  rep(i, s) {
    sum[L[i]]++;
    sum[R[i] + 1]--;
  }
  vector<ll> res(N + 1);
  for(int i = 1; i <= N; ++i) {
    if (i == 1) {
      res[i] = sum[i];
    } else {
      res[i] = res[i - 1] + sum[i];
    }
  }
  return res;
}

int main() {
  int D, N;
  cin >> D >> N;

  vector<ll> L(N);
  vector<ll> R(N);
  rep(i, N) {
    cin >> L[i] >> R[i];
  }

  vector<ll> ans = imos(D, L, R);

  for(int i = 1; i <= D; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}
