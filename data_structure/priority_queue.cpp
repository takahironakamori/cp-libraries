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
  priority_queue<int> que;

  /*
  小さい順に取り出したいとき
  priority_queue<型, vector<型>, greater<型>> 変数名;
  */

  // 要素を追加する
  que.push(1);
  que.push(2);

  // 最大の要素を取得する
  cout << que.top() << endl;

  // 最大の要素を削除する
  que.pop();

  // 空でない間繰り返す
  while(!que.empty()) {
    cout << que.top() << endl;  // 最大の値を出力
    que.pop();                  // 最大の値を削除
  }
  
  return 0;
}
