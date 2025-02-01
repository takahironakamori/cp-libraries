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

// 0 から cnt - 1 までをランダムに並び替える
random_device rd;
mt19937 gen(rd());
vector<int> shuffleNumbers(int cnt) {
  vector<int> v(cnt);
  iota(v.begin(), v.end(), 0);
  for (int i = cnt - 1; i > 0; --i) {
    uniform_int_distribution<int> dist(0, i);
    swap(v[i], v[dist(gen)]);
  }
  return v;
}

int main() {

  vector<int> v(10);
  rep(i, 10) {
    v[i] = i + 1;
  }

  // check
  rep(i, 10) {
    cout << v[i] << " ";
  }
  cout << endl;

  // 0 から cnt - 1 までをランダムに並び替える
  vector<int> v2 = shuffleNumbers(10);

  // debug
  rep(i, 10) {
    cout << v[v2[i]] << " ";
  }
  cout << endl;

  return 0;
}