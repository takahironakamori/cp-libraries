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
 * c ... 区切る基準の文字
 */
vector<string> splitString(string &s, char c) {
  vector<string> v;
  stringstream ss(s);
  string buffer;
  while (getline(ss, buffer, c)) {
    v.push_back(buffer);
  }
  return v;
}

int main() {

  string S = "ABCD:EFG";
  vector<string> v = splitString(S, ':');

  for(auto i: v) {
    cout << i << endl;
  }
  
  return 0;
}
