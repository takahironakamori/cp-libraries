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

class MinCostFlow {
  public:
    using Edge = tuple<int, ll, ll, int>;

    MinCostFlow(int V) {
      V_ = V;
      G_.resize(V_);
    }

    void add_edge(int u, int v, ll capacity, ll cost) {
      G_[u].emplace_back(v, capacity, cost, G_[v].size());
      G_[v].emplace_back(u, 0, -cost, G_[u].size());
    }

    tuple<vector<ll>, vector<int>, vector<int>> bellman_ford(int s) {
      vector<ll> dist(V_, INF);
      dist[s] = 0;
      vector<int> pv(V_);
      vector<int> pe(V_);
      while(true) {
        bool update = false;
        rep(i, V_) {
          if(dist[i] == INF) {
            continue;
          }
          rep(j, (int)G_[i].size()) {
            auto [nxt, capacity, cost, rev] = G_[i][j];
            if (0 < capacity && dist[i] + cost < dist[nxt]) {
              dist[nxt] = dist[i] + cost;
              update = true;
              pv[nxt] = i;
              pe[nxt] = j;
            }
          }
        }
        if (!update) {
          break;
        }
      }
      return make_tuple(dist, pv, pe);
    }

    ll calc_min_cost_flow(int s, int t, ll f) {
      ll result = 0;
      while(0 < f) {
        auto [dist, pv, pe] = bellman_ford(s);
        if (dist[t] == INF) {
          return INF;
        }
        ll flow = f;
        int v = t;
        while(v != s) {
          flow = min(flow, get<1>(G_[pv[v]][pe[v]]));
          v = pv[v];
        }
        result += flow * dist[t];
        f -= flow;
        v = t;
        while(v != s) {
          get<1>(G_[pv[v]][pe[v]]) -= flow;
          int rev = get<3>(G_[pv[v]][pe[v]]);
          get<1>(G_[v][rev]) += flow;
          v = pv[v];
        }
      }
      return result;
    }

private:
  int V_;
  vector<vector<Edge>> G_;
};

int main() {
  int V, E, F;
  cin >> V >> E >> F;

  MinCostFlow mincost_flow(V);

  rep(i, E) {
    int u, v, capacity, cost;
    cin >> u >> v >> capacity >> cost;
    u--;
    v--;
    mincost_flow.add_edge(u, v, capacity, cost);
  }

  cout << mincost_flow.calc_min_cost_flow(0, V - 1, F) << endl;
  return 0;
}
