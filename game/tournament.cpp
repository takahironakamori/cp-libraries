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
  int n = 1 << N;

  rep(i, N) {
    rep(j, n) {
      int M = i + 1;
      // 対戦する可能性がある範囲 [l, r)
      int l = (int)(j / pow(2, M)) * pow(2, M);
      int r = (int)(j / pow(2, M) + 1) * pow(2, M);

      if (i == 0) {
        // 1回戦の場合
        for (int k = l; k < r; ++k) {
          if (k == j) { continue; }
          cout << "人" << (j + 1) << "の" << (i + 1) << "回戦の相手" << " " << (k + 1) << endl;
        }
      } else {
        // 1回戦以外の場合
        // 過去に対戦していて対戦する可能性がない範囲 [l2, r2)
        int l2 = (int)(j / pow(2, i)) * pow(2, i);
        int r2 = (int)(j / pow(2, i) + 1) * pow(2, i);

        cout << "人" << (j+1) << "の" << (i + 1) << "回戦の相手" << " ";
        for (int k = l; k < r; ++k) {
          if (k == j) { continue; }
          if (l2 <= k && k < r2) {
            continue;
          }
          cout << (k + 1) << " ";
        }
        cout << endl;
      }
    }
  }
  return 0;
}
