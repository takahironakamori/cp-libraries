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
  int v;
  cin >> v;

  // 定義
  set<int> A;
  
  // 降順にしたい場合
  set<int, greater<int>> B;

  // vを追加
  A.insert(v);

  // vを削除
  A.erase(v);

  // 要素数を数える
  int cnt = A.size();

  // vを探す(ない場合はend()を返す)
  auto itr = A.find(v);

  // vの数を数える(0か1を返す)
  A.count(v);
  
  // 最小値を出力
  cout << *A.begin() << endl;

  // 最大値を出力
  cout << *A.rbegin() << endl;

  // 順番に出力する
  for(auto x : A) {
    cout << x << endl;
  }
  
  // 4 以上の要素のうち最小の要素のイテレータを取得
  auto it = st.lower_bound(4); 
  
  // it の示す要素を出力
  cout << *it << endl;
  
  // it の1つ前のイテレータの示す要素を出力
  cout << *prev(it) << endl;
  
  // it の1つ次のイテレータの示す要素を出力
  cout << *next(it) << endl;

  return 0;
}
