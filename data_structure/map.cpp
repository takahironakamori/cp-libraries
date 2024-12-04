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
  map<string, int> mp;

  // 降順にしたい場合
  // map<string, int, greater<string>> mp;

  // データを追加する
  mp["C"] = 3;
  mp["B"] = 2;
  mp["A"] = 0;
  mp["E"] = 5;
  mp["D"] = 1;

  // データを取得する
  int v = mp["A"];

  // mapの長さを確認する
  cout << mp.size() << endl;
  
  // 最初の要素を得る
  auto [s, v] = *mp.begin();
  
  // 最初の要素を削除する（イテレータを使う）
  mp.erase(mp.begin());

  // Keyの有無を確認する ある場合は要素の数（1以上）、ない場合は0
  int hasKey = mp.count("A");

  // mapのkeyとvalueを巡回する
  for(auto item : mp) {
    cout << item.first << ":" << item.second << endl;
  }

  // mapを空にする
  mp.clear();
  
  return 0;
}
