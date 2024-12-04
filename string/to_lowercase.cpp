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
 * 大文字の文字列を小文字の文字列にする
 * s ... 大文字の文字列
 */
string toLowercaseString(string s) {
  string res = "";
  rep(i, (int) s.size()) {
    int v = (int) s[i];
    res += char(v + 32);
  }
  return res;
}

int main() {

  string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  cout << toLowercaseString(s) << endl;
  
  return 0;
}
