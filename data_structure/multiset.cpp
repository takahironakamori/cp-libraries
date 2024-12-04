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
  multiset<int> st;

  // 追加
  st.insert(2);
  st.insert(3);
  st.insert(2);
  st.insert(4);
  st.insert(1);
  st.insert(3);

  // 順番に出力する（1 2 2 3 3 4 が出力される）
  for(auto x : st) {
    cout << x << " ";
  }
  cout << endl;
  
  // 削除 2を全部消す
  st.erase(2);
  
  // イテレータを渡すとその要素だけを削除する
  st.erase(イテレータ);

  // 数を数える
  int siz = st.size();

  // 有無を調べる
  if(st.find(2) != st.end()) {
    cout << "2はあります" << endl;
  } else {
    cout << "2はありません" << endl;
  }

  // 最小値（1）を出力
  cout << *st.begin() << endl;

  // 最大値（4）を出力
  cout << *st.rbegin() << endl;

  // 順番に出力する（1 3 3 4 が出力される）
  for(auto x : st) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
