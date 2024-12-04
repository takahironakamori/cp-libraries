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
const ll INF = 1LL << 62;
// const int INF = 1001001001;

class Flow {
  public:
    using Edge = tuple<int, ll, int>;

    Flow(int value) {
      value_ = value;
      graph_.resize(value_);
    }

    void add_edge(int u, int v, ll c) {
      graph_[u].emplace_back(v, c, (int) graph_[v].size());
      graph_[v].emplace_back(u, 0, (int) graph_[u].size() - 1);
    }

    vector<int> bfs(int s) {
      vector<int> d(value_, -1);
      d[s] = 0;
      queue<int> que;
      que.emplace(s);
      while(!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto [nxt, capacity, rev] : graph_[u]) {
          if (0 < capacity && d[nxt] < 0) {
            d[nxt] = d[u] + 1;
            que.emplace(nxt);
          }
        }
      }
      return d;
    }

    ll dfs(int v, int t, ll f, vector<int> &removed, vector<int> &d) {
      if (v == t) {
        return f;
      }

      while (removed[v] < (int) graph_[v].size()) {
        auto [nxt, capacity, rev] = graph_[v][removed[v]];
        if (0 < capacity && d[v] < d[nxt]) {
          int flow = dfs(nxt, t, min(f, capacity), removed, d);
          if (0 < flow) {
            get<1>(graph_[v][removed[v]]) -= flow;
            get<1>(graph_[nxt][rev]) += flow;
            return flow;
          }
        }
        removed[v] += 1;
      }
      return 0;
    }

    ll calc_max_flow (int s, int t) {
      ll flow = 0;
      while (true) {
        vector<int> d = bfs(s);
        if (d[t] < 0) {
          return flow;
        }
        vector<int> removed(value_, 0);
        while(true) {
          ll f = dfs(s, t, INF, removed, d);
          if (f == 0) {
            break;
          }
          flow += f;
        }
      }
      return flow;
    }

  private:
    vector<vector<Edge>> graph_;
    int value_;
};

int main() {
  int N;
  cin >> N;

  int V = 2 * N + 2;

  Flow flow(V);
  rep(i, N) {
    string c;
    cin >> c;

    rep(j, N) {
      if (c[j] == '#') {
        flow.add_edge(i + 1, N + j + 1, 1);
      }
    }
  }

  rep(i, N) {
    flow.add_edge(0, i + 1, 1);
    flow.add_edge(N + i + 1, 2 * N + 1, 1);
  }

  ll ans = flow.calc_max_flow(0, 2 * N +1);
  cout << ans << endl;
  return 0;
}
