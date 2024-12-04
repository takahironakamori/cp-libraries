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
 * s に t が部分列（連続じゃなくていい）として先頭から何文字含まれているかを返す
 * @param {string} s 文字列s
 * @param {string} t 文字列t
 * @return {int} 含まれている文字数
 */
int countCommonPrefixSubsequence (const string& s, const string& t) {
  int cnt_ = 0;
  int s_ = (int) s.size();
  int t_ = (int) t.size();
  for (int i = 0; i < s_; ++i) {
    if (t_ <= cnt_) { break; }
    if (s[i] == t[cnt_]) {
      cnt_++;
    }
  }
  return cnt_;
}

int main() {

  string S;
  string T;
  cin >> S >> T;

  cout << countCommonPrefixSubsequence(S, T) << endl;

  return 0;
}
