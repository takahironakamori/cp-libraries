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

  string T1 = "abcde";
  string S1 = "ab";

  // 文字列 S1 を文字列 T1 の長さに合わせる足りない部分は "z" で埋める。
  S1.resize((int) T1.size(), 'z');

  // abzzz と表示される
  cout << S1 << endl;
  
  return 0;
}
