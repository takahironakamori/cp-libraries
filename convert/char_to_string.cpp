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

  // 方法その1
  char c1 = 'B';
  string str1;
  str1 += c1; // char を追加
  cout << str1 << endl;

  // 方法その2
  char c2 = 'C';
  string str2 = string(1, c2); // 1文字として割り当てる
  cout << str2 << endl; // 出力: C

  return 0;
}
