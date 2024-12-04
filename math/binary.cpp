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

// 10進数を2進数（string）に変換する
string binary(ll v) {
  string result = "";
  for(int i = 0; 0 < v; i++) {
    result += to_string(v % 2);
    v = v / 2;
  }
  reverse(result.begin(), result.end());
  return result;
}


int main() {
  ll N;
  cin >> N;

  string res = binary(N);

  cout << res << endl;
  return 0;
}
