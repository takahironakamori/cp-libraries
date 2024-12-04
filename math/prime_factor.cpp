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

// N 以下の素数を列挙する
vector<int> prime_factor(ll v) {
  vector<bool> is_prime(v + 1);
  for(int i = 0; i <= v; i++) {
    is_prime[ i ] = true;
  }
  vector<int> res;
  for(int i = 2; i <= v; i++) {
    if(is_prime[i]) {
      for(int j = 2 * i; j <= v; j += i) {
        is_prime[ j ] = false;
      }
      res.emplace_back( i );
    }
  }
  return res;
}

int main() {
  vector<int> res = prime_factor(1000);

  for(auto i:res) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
