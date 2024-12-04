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

// start 以上、end 以下でランダムなintを返す
random_device rd;
default_random_engine eng(rd());
int generate_random(int start, int end) {
  uniform_real_distribution<double> distr(start - 1, end);
  return ceil(distr(eng));
}

int main() {

  // 10 以上 100 以下のランダムな数を生成する。
  int res = generate_random(10, 100);

  cout << res << endl;
  return 0;
}
