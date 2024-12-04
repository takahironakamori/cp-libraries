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

  string S = "ABCDEFGHI";

  // x文字目以降を出力する
  // EFGHI
  cout << S.substr(4) << endl;

  // x文字目からy文字出力する
  // EF
  cout << S.substr(4,2) << endl;
  
  return 0;
}
