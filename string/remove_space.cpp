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
 * s ... 対象の文字列
 */
string removeSpace(string &s) {
  s.erase(remove(s.begin(), s.end(), ' '), s.end());
  return s;
}

int main() {

  string s = "This is a pen.";

  cout << removeSpace(s) << endl;

  return 0;
}
