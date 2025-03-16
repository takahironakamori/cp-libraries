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

// N: 円環の点の数
// A, B: 計算する2つの点 (1-based index)
int shortest_distance(int N, int A, int B) {
  // 時計回りの距離
  int clockwise = (B - A + N) % N;
  // 反時計回りの距離
  int counter_clockwise = (A - B + N) % N;
  
  return min(clockwise, counter_clockwise);
}

int main() {
  int N;
  cin >> N;

  int from, to;
  cin >> from >> to;

  cout << shortest_distance(N, from, to) << endl;
  return 0;
}
