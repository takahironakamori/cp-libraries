#include <iostream>
#include <vector>
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

  // v = 3 : bit全探索の0,1,2版
  int v = 3;
  vector<int> p(N + 1, 1);
  rep(i, N) {
    p[i + 1] = p[i] * v;
  }

  rep(s, p[N]) {
    vector<int> T(N);
    rep(i, N) {
      T[i] = s / p[i] % v;
    }
    // 0 0 0, 1 0 0, 2 0 0, 0 1 0,...という感じで出力
    rep(i, N) {
      cout << T[i] << " ";
    }
    cout << endl;
  }

  return 0;
}