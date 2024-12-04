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

// N を素因数分解したものを返す
map<ll, ll> prime_factor(ll N) {
  map<ll, ll> mp;
  for (ll i = 2; i * i <= N; ++i) {
    while (N % i == 0) {
      mp[i]++;
      N /= i;
    }
  }
  if (N != 1) {
    mp[N] = 1;
  }
  return mp;
}

int main() {
  l N;
  cin >> N;

  map<ll, ll> mp = prime_factor(N);
  for (auto i:mp) {
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}
