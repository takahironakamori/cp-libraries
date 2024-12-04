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
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i, H) cin >> S[i];

  vector<int> dy = {1, -1, 0, 0, 1, -1, -1, 1};
  vector<int> dx = {0, 0, 1, -1, 1, -1, 1, -1};

  vector<char> snuke = {'s','n','u','k','e'};

  rep(i, H) {
    rep(j, W) {
      if (S[i][j] == 's') {
        vector<P> ans(5);
        ans[0] = make_pair(i + 1, j + 1);
        rep(k, 8) {
          bool flg = true;
          for (int l = 1; l < 5; ++l) {
            int ni = i + (dy[k] * l);
            int nj = j + (dx[k] * l);
            if (ni < 0 || H <= ni || nj < 0 || W <= nj) {
              flg = false;
            } else {
              if (S[ni][nj] == snuke[l]) {
                ans[l] = make_pair(ni + 1, nj + 1);
              } else {
                flg = false;
              }
            }
          }
          if (flg) {
            for(auto m:ans){
              cout << m.first << " " << m.second << endl;
            }
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
