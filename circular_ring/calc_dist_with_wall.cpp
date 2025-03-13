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

/**
 * size ... 円環の大きさ
 * ng ... 通れない場所
 */
int calc_dist(int size, int from, int to, int ng) {
  if (from > to) {
    swap(from, to);
  }
  if (from < ng and ng < to) {
    return size + from - to;
} else {
    return to - from;
}
}

int main() {
  int N;
  cin >> N;

  int from, to, ng;
  cin >> from >> to >> ng;

  cout << calc_dist(N, from, to, ng) << endl;
  return 0;
}
