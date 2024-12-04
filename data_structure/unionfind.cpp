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

struct UnionFind {
  vector<int> par, rank, siz;

  UnionFind(int n) : par(n, -1), rank(n, 0), siz(n,1) {}

  int root(int x) {
    if (par[x] == -1) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }

  bool isSame(int x, int y) {
    return root(x) == root(y);
  }

  bool unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) {
      return false;
    }
    if (rank[rx] < rank[ry]) {
      swap(rx, ry);
    }
    par[ry] = rx;
    if (rank[rx] == rank[ry]) {
      rank[rx]++;
    }
    siz[rx] += siz[ry];
    return true;
  }

  int size(int x) {
    return siz[root(x)];
  }
};

int main() {
  int N, M;
  cin >> N >> M;

  // 定義
  UnionFind uf(N);

  int A, B;
  cin >> A >> B;

  // AとBが同じグループか否かをチェック
  bool flg = uf.isSame(A, B);

  // AとBをつなぐ
  uf.unit(A, B);

  // Aの根を取得する
  int res = uf.root(A);

  // Aのグループのサイズを取得する
  int size = uf.size(A);

  return 0;
}
