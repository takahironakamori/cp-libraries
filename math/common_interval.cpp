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

// 2つの区間の共通部分の長さが 0 の場合は true を返す
// p1.first < p1.second
// p2.first < p2.second
bool f(P p1, P p2) {
  if (p1.second <= p2.first || p2.second <= p1.first) {
    return true;
  } else {
    return false;
  }
}

int main() {
  P p1 = make_pair(1, 7);
  P p2 = make_pair(4, 10);

  if (f(p1, p2)) {
    cout << "共通部分は0" << endl;
  } else {
    cout << "共通部分がある" << endl;
  }
  return 0;
}
