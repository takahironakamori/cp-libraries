#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
// using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

// 全方位木 DP (rerooting)
// 以下のコードをもとに作成しています。
// https://github.com/drken1215/algorithm/blob/master/Tree/rerooting.cpp

template<class Monoid> struct Rerooting {
  
  vector<vector<int>> G;
  Monoid IDENTITY;
  function<Monoid(Monoid, Monoid)> MERGE;
  function<Monoid(int, Monoid)> ADDNODE;

  vector<vector<Monoid>> dp;

  Rerooting(){}
  Rerooting(
    const vector<vector<int>> &g,
    const Monoid &identity,
    const function<Monoid(Monoid, Monoid)> &merge,
    const function<Monoid(int, Monoid)> &addnode
  ){
    G = g;
    IDENTITY = identity;
    MERGE = merge;
    ADDNODE = addnode;
    build();
  }

  Monoid rec(int v, int p) {
    Monoid res = IDENTITY;
    dp[v].assign(G[v].size(), IDENTITY);
    rep(i, (int) G[v].size()) {
      int v2 = G[v][i];
      if(v2 == p) {
        continue;
      }
      dp[v][i] = rec(v2, v);
      res = MERGE(res, dp[v][i]);
    }
    return ADDNODE(v, res);
  }

  void rerec(int v, int p, Monoid pval) {
    rep(i, (int) G[v].size()) {
      int v2 = G[v][i];
      if(v2 == p) {
        dp[v][i] = pval;
        continue;
      }
    }
    vector<Monoid> left(G[v].size() + 1, IDENTITY);
    vector<Monoid> right(G[v].size() + 1, IDENTITY);
    rep(i, (int) G[v].size()) {
      left[i + 1] = MERGE(left[i], dp[v][i]);
      right[i + 1] = MERGE(right[i], dp[v][(int) G[v].size() - i - 1]);
    }
    rep(i, (int) G[v].size()) {
      int v2 = G[v][i];
      if(v2 == p) {
        continue;
      }
      Monoid pval2 = MERGE(left[i], right[(int) G[v].size() - i - 1]);
      rerec(v2, v, ADDNODE(v, pval2));
    }
  }

  void build() {
    dp.assign(G.size(), vector<Monoid>());
    int root = 0;
    int nullparent = -1;
    rec(root, nullparent);
    rerec(root, nullparent, IDENTITY);
  }

  // GETTER
  Monoid get(int v) {
    Monoid res = IDENTITY;
    rep(i, (int) G[v].size()) {
      res = MERGE(res, dp[v][i]);
    }
    return ADDNODE(v, res);
  }

};


// Example
//
// EDPC-V Subtree
// https://atcoder.jp/contests/dp/tasks/dp_v

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> graph(N);
  rep(i, N - 1) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  // Monoid の型を指定
  using Monoid = ll;

  Monoid identity = 1;
  auto merge = [&](Monoid a, Monoid b) -> Monoid { return a * b % M; };
  auto addnode = [&](int v, Monoid a) -> Monoid { return (a + 1) % M; };
  Rerooting<Monoid> rerooting(graph, identity, merge, addnode);

  rep(i, N) {
    cout << (rerooting.get(i) + M - 1) % M << endl;
  }
  return 0;
}
