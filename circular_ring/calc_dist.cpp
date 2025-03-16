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

/**
 * size ... 円環の大きさ
 */
ll calc_dist(ll size, ll from, ll to) {
  if (from <= to) {
    return to - from; 
  } else {
    return to + size - from;
  }
}

int main() {
  int N;
  cin >> N;

  int from, to;
  cin >> from >> to;

  cout << calc_dist(N, from, to) << endl;
  return 0;
}
