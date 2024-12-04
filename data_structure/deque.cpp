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
  deque<int> que;
  
  // 要素を追加する
  que.push_back(1);
  que.push_front(2);
  que.push_front(3);
  que.push_front(4);
  
  // 2番目の要素を出力する
  cout << que[1] << endl; 

  while(!que.empty()) {
    cout << que.front() << " ";
    que.pop_front();

    // cout << que.back() << " ";
    // que.pop_back();
  }

  // 配列の中から、A[i]が入る場所（A[i]以下で、A[i]に近いところ）のイテレータを返す
  // int p = lower_bound(que.begin(), que.end(), A[i]) - que.begin();
  
  return 0;
}
