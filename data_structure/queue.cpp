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

  // 初期化
  queue<int> que;

  // 要素を追加する
  que.push(1);
  que.push(2);
  que.push(3);

  // 1 2 3 と出力する
  while(!que.empty()) {
    cout << que.front() << " ";
    que.pop();
  }

  return 0;
}
