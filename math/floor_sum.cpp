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

// (ax+b)/m の合計を計算する
ll calcFloorSum(ll N, ll M, ll A, ll B) {
  return floor_sum(N, M, A, B);
}

int main() {
  ll N, M, A, B;
  cin >> N >> M >> A >> B;

  ll ans = calcFloorSum(N, M, A, B);
  cout << ans << endl;
  
  return 0;
}
