#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
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
  int N, M;
  cin >> N >> M;

  dsu uf(N);

  bool hasLoop;

  rep(i, M) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    if(uf.leader(u) == uf.leader(v)) {
      hasLoop = true;
    }
    uf.merge(u, v);
  }

  if(hasLoop) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}