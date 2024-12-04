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
  int N;
  cin >> N;

  // 初期化して受け取る
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
  }

  // 配列の要素数を変更する
  A.resize(10);
  
  // 最初の要素を取得する
  int f = A.front();
  
  // 最後の要素を取得する
  int l = A.back();

  // 後ろにvを追加
  A.push_back(v);
  A.emplace_back(v);

  // 途中(k番目）に追加
  A.insert(A.begin() + k, v);

  // 最後の要素を削除
  A.pop_back();

  // 途中(k番目）の要素を削除
  A.erase(A.begin() + k);

  // 配列の中でvの個数を数える
  int cnt = count(A.begin(), A.end(), v);

  // 配列の中で最小値を取得する
  int mn = *min_element(A.begin(), A.end());

  // 配列の中で最大値を取得する
  int mx = *max_element(A.begin(), A.end());

  // 配列から最初にvが表れる位置を得る。
  int pos = find(A.begin(), A.end(), v) - A.begin(); 

  // 配列を昇順に並び替える
  sort(A.begin(), A.end());

  // 配列を降順に並び替える
  sort(A.rbegin(), A.rend());

  // 配列内の重複している要素を消す
  A.erase(unique(A.begin(), A.end()), A.end());

  // 配列をvで埋める
  fill(A.begin(), A.end(), v);
  
  return 0;
}
