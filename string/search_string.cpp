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
 * f ... 探したい文字列
 * 
 * 見つかったら場合はその場所、
 * 見つからない場合は-1を返す
 */
int searchString(string &s, string f) {
  if (s.find(f) != string::npos) {
    return s.find(f);
  } else {
    return -1;
  }
}

int main() {

  string s = "ABDE";
  
  cout << searchString(s, "D") << endl;
  cout << searchString(s, "C") << endl;
  
  return 0;
}
