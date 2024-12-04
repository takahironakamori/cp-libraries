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

// res[i][c] := i 文字目以降で最初に文字 c が登場する index
// 存在しないときは N
vector<vector<int>> calc_next(string &S) {
  int N = (int) S.size();
  vector<vector<int>> res(N+1, vector<int>(26, N));
  for (int i = N - 1; 0 <= i; i--) {
    res[i] = res[i+1];
    res[i][S[i] - 'a'] = i;
  }
  return res;
}

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  // 前処理
  auto nex = calc_next(S);

  string ans = "";

  // 貪欲法
  int j = -1;
  for (int i = 0; i < K; ++i) {
    for (int k = 0; k < 26; ++k) {
      int v = nex[j+1][k];
      // K 文字作れたら OK
      if (K - i <= N - v) {
        ans += char(k + 'a');
        j = v;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
