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

// BIT(Fenwick Tree) とは長さ N の配列に対し、
// ・要素の1点を変更する
// ・区間の要素の総和を求める
// 以上をO(log N) で求めることができるデータ構造である。

int main() {
  ll N, Q;
  cin >> N >> Q;

  fenwick_tree<ll> ft(N);
  rep(i, N) {
    int a;
    cin >> a;
    ft.add(i, a);
  }

  rep(i, Q) {
    int T;
    cin >> T;
    if(T == 0) {
      int p, x;
      cin >> p >> x;
      ft.add(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << ft.sum(l, r) << endl;
    }
  }
  return 0;
}
