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

// 文字列が回文か否かを返す
bool isPalindrome(string s) {
  int n = (int)s.size();
  int center = (int)s.size() / 2;
  for(int i = 0; i < center; ++i) {
    if (s[i] != s[n - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  string S;
  cin >> S;

  bool flg = isPalindrome(S);
  return 0;
}
