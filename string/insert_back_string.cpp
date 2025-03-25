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
  string s;
  cin >> s;

  // 最後の文字を先頭に挿入して、
  // 最後の文字を消す
  s.insert(begin(s), s.back());
  s.pop_back();

  cout << s << endl;
  return 0;
}