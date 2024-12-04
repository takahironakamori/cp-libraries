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

/**
 * s と t で先頭から見て何文字目まで一致するかを返す
 * @param {string} s 文字列s
 * @param {string} t 文字列t
 * @return {int} 一致している文字数
 */
int countMatchingPrefix (const string& s, const string& t) {
  int cnt_ = 0;
  bool flg_ = true;
  int s_ = (int) s.size();
  int t_ = (int) t.size();
  while (flg_) {
    if (s_ <= cnt_ || t_ <= cnt_) {
      flg_ = false;
      break;
    }
    if (s[cnt_] == t[cnt_]) {
      cnt_++;
    } else {
      flg_ = false;
    }
  }
  return cnt_;
}

int main() {
  string S;
  string T;
  cin >> S >> T;

  cout << countMatchingPrefix(S, T) << endl;
  return 0;
}
