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

  // 定義
  tuple<int, bool, string> tup;
  
  // 値を入れる
  tup = make_tuple(1, true, "name");

  // 2番目の値を変更する
  get<1>(tup) = false;

  // 3番目を出力する
  cout << get<2>(tup) << endl;

  // 分解して値を持って出力する
  int a;
  bool b;
  string c;
  tie(a, b, c) = tup;
  cout << a << " " << b << " " << c << endl;
  
  return 0;
}
