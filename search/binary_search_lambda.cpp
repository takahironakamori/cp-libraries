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
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
  }

  auto check = [&](int v) {
    ll sum = 0;
    rep(i, N) {
      sum += (ll) v / A[i];
    }
    if (sum < K) {
      return true;
    } else {
      return false;
    }
  };

  int ac = 1;
  int wa = 1000000000;
  while (1 < wa - ac) {
    int mid = (wa + ac) / 2;
    if (check(mid)) {
      ac = mid;
    } else {
      wa = mid;
    }
  }

  cout << ac+1 << endl;
  return 0;
}
