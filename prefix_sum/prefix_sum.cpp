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

// (N + 1) の累積和を返す
vector<ll> createPrefixSum(int N, vector<ll> &v) {
  vector<ll> sum(N+1);
  for(int i = 1; i <= N; ++i) {
    if (i == 1) {
      sum[i] = v[i - 1];
    } else {
    sum[i] = sum[i - 1] + v[i - 1];
    }
  }
  return sum;
}

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
  }

  vector<ll> sum = createPrefixSum(N, A);

  rep(i, Q){
    int L, R;
    cin >> L >> R;
    cout << sum[R] - sum[L-1] << endl;
  }
  return 0;
}
