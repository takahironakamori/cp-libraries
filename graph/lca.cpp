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

class LowestCommonAncestor {
  public:
    using EdgeCostType = int;

    LowestCommonAncestor(int n) {
      n_ = n;
      logn_ = (int) log2(n_) + 2.0;
      depth_.resize(n_, 0);
      distance_.resize(n_, (EdgeCostType) 0);
      ancestor_.resize(logn_, vector<int>(n_, -1));
      edges_.resize(n_);
    }

    void add_edge(int u, int v, EdgeCostType w = 1) {
      edges_[u].emplace_back(v, w);
      edges_[v].emplace_back(u, w);
    }

    void build(int root = 0) {
      stack<int> st;
      st.emplace(root);

      while (st.size()) {
        int current = st.top();
        st.pop();
        for (auto [nxt, w] : edges_[current]) {
          if (ancestor_[0][nxt] != current && ancestor_[0][current] != nxt) {
            ancestor_[0][nxt] = current;
            depth_[nxt] = depth_[current] + 1;
            distance_[nxt] = distance_[current] + w;
            st.emplace(nxt);
          }
        }
      }

      for (int k = 1; k < logn_; k++) {
        for (int i = 0; i < n_; i++) {
          if (ancestor_[k - 1][i] == -1) {
            ancestor_[k][i] = -1;
          } else {
            ancestor_[k][i] = ancestor_[k - 1][ancestor_[k - 1][i]];
          }
        }
      }
    }

    int lca(int u, int v) {
      if (depth_[v] < depth_[u]) {
        swap(u, v);
      }

      for (int k = logn_ - 1; 0 <= k; k--) {
        if (((depth_[v] - depth_[u]) >> k) & 1) {
          v = ancestor_[k][v];
        }
      }

      if (u == v) {
        return u;
      }

      for (int k = logn_ - 1; 0 <= k; k--) {
        if (ancestor_[k][u] != ancestor_[k][v]) {
          u = ancestor_[k][u];
          v = ancestor_[k][v];
        }
      }

      return ancestor_[0][u];
    }

    EdgeCostType distance(int u, int v) {
      return distance_[u] + distance_[v] - 2 * distance_[lca(u, v)];
    }

  private:
    int n_;
    int logn_;
    vector<int> depth_;
    vector<EdgeCostType> distance_;
    vector<vector<int>> ancestor_;
    vector<vector<pair<int, EdgeCostType>>> edges_;
};

int main() {
  int N;
  cin >> N;

  LowestCommonAncestor tree(N);

  rep (i, N-1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.add_edge(a, b);
  }

  tree.build();

  int Q;
  cin >> Q;
  rep(i, Q) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    cout << tree.lca(u, v) + 1 << endl;
  }
  return 0;
}
