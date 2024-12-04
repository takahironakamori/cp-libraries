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

/*
 * c ... 文字
 */
int getASCII(char c) {
  return (int) c;
}


int main() {

  string S1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  rep(i, (int)S1.size()) {
    cout << getASCII(S1[i]) << endl;
  }
  
  string S2 = "abcdefghijklmnopqrstuvwxyz";
  
  rep(i, (int)S2.size()) {
    cout << getASCII(S2[i]) << endl;
  }
  
  return 0;
}
