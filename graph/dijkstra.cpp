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

int N, M;

struct Edge {
  int to;
  ll cost;
};

vector<vector<Edge>> graph;
vector<ll> dist;
vector<bool> visited;
priority_queue<P, vector<P>, greater<P>> pq;

void dijkstra() {
  while(!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if (visited[v]) { continue; }
    visited[v] = true;
    for(int i = 0; i < int(graph[v].size()); ++i) {
      int to = graph[v][i].to;
      ll cost = graph[v][i].cost;
      if(dist[v] + cost < dist[to]) {
        dist[to] = dist[v] + cost;
        pq.push(make_pair(dist[to], to));
      }
    }
  }
  return;
}

int main() {
  cin >> N >> M;

  graph.resize(N);
  dist.resize(N);
  visited.resize(N);

  rep(i, M) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    u--;
    v--;

    Edge a;
    a.to = v;
    a.cost = c;

    Edge b;
    b.to = u;
    b.cost = c;

    graph[u].push_back(a);
    graph[v].push_back(b);
  }

  rep(i, N) dist[i] = INF;
  dist[0] = 0;
  pq.push(make_pair(dist[0], 0));
  dijkstra();

  for(auto i:dist) {
    if (i == INF) {
      cout << "-1" << endl;
    } else {
      cout << i << endl;
    }
  }
  return 0;
}
