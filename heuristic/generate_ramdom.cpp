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
mt19937 eng(rd());
int generateRandom(int start, int end) {
  uniform_int_distribution<int> distr(start, end);
  return distr(eng);
}

int main() {

  // 10 以上 100 以下のランダムな数を生成する。
  int res = generateRandom(10, 100);

  cout << res << endl;
  return 0;
}
