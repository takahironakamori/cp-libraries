#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, ll>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
// using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

/*
数 n を1桁ずつ構成すると考えたとき、以下のようになります。
例えば、ある桁までの値を X とし、新しい桁を d とします。
新しい値 Y は次のように表せます：
Y = 10 * X + d
つまり、新しい数値は「これまでの数値を10倍して、新しい桁 d を足したもの」です。
*/

int main() {
  int k = 7;
  int now = 12;
  int next = 123;
  
  int now_mod = now % k;

  // 新しい余り = ((今の余り * 10) + 次の数) % k //
  int next_mod = (now_mod * 10 + 3) % k;
  
  cout << next_mod << endl;
  return 0;
}
