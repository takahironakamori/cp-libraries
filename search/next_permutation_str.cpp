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
  string S;
  cin >> S;

  sort(S.begin(), S.end());

  // 文字列の順列を生成する
  do {
    cout << S << endl;
  } while(next_permutation(S.begin(), S.end()));
  
  return 0;
}
