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
  int N;
  cin >> N;

  // 0 から N までで 0 or 1 の全パターンを出力する
  // 例 3:{0 1 }
  for(int bits = 0; bits < (1 << N); bits++) {
    vector<int> bit;

    for(int i = 0; i < N; i++) {
      if(bits >> i & 1) {
        bit.push_back(i);
      }
    }

    // 出力
    cout << bits << ": {";
    for(int i = 0; i < bit.size(); i++) {
      cout << bit[i] << " ";
    }
    cout << "}" << endl;
  }
  return 0;
}