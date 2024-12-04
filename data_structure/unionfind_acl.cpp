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
  int N, Q;
  cin >> N >> Q;

  dsu uf(N);

  rep(i, Q) {
    int t, u, v;
    cin >> t >> u >> v;
    if(t == 0) {
      uf.merge(u, v);
    } else {
      if(uf.same(u, v)) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
  
  // 頂点 n の属する連結成分の代表元を得る
  int n = 1
  int leader = uf.leader(n);
  
  // 頂点 n の属する連結成分のサイズを得る
  int nsize = uf.size(n); 

  // すべての連結成分の大きさを出力する
  for(auto i:uf.groups()) {
    cout << (int)i.size() << " ";
  }
  cout << endl;
  
  return 0;
}
