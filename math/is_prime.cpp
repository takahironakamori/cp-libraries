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

// 素数判定
bool is_prime(ll N) {
  for(ll i = 2; i * i <= N; i++) {
    if(N % i == 0) {
      return false;
    }
  }
  return N != 1;
}

int main() {
  ll N;
  cin >> N;

  if(is_prime(N)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
