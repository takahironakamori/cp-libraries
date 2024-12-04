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

vector<ll> divisor(ll N) {
  vector<ll> res;
  for (ll i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      res.push_back(i);
      if (i != N / i) {
        res.push_back(N / i);
      }
    }
  }
  return res;
}

int main() {
  ll N;
  cin >> N;

  vector<ll> res = divisor(N);

  // 約数の数を出力する
  cout << (int) res.size() << endl;

  // 約数を出力する
  rep(i, (int) res.size()) {
    cout << res[i] << endl;
  }
  return 0;
}