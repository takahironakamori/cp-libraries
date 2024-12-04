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

// a と b の最大公約数を返す
ll gcd(ll a, ll b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

// a と b の最小公倍数を返す
ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main() {
  ll a, b;
  cin >> a >> b;

  cout << lcm(a, b) << endl;
  
  return 0;
}
