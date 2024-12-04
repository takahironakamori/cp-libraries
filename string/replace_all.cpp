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
 * s    ... 元の文字列
 * from ... 変更前
 * to   ... 変更後
 */
string replaceAll(string &s, string from, string to) {
  int pos = s.find(from);
  int toLen = to.length();
  if (from.empty()) {
    return s;
  }
  while ((pos = s.find(from, pos)) != string::npos) {
    s.replace(pos, from.length(), to);
    pos += toLen;
  }
  return s;
}

int main() {
  string s = "testtesttest11";
  
  string ans = replaceAll(s, "test", "1");
  cout << ans << endl;
  return 0;
}
