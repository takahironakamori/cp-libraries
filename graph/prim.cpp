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

int N, M;

vector<vector<P>> graph;
vector<bool> used;
priority_queue<P, vector<P>, greater<P>> pq;
ll ans;

void prim() {
 while(!pq.empty()) {
  P p = pq.top();
  pq.pop();
  ll cost = p.first;
  int v = p.second;
  if (used[v]) {
   continue;
  }
  used[v] = true;
  ans += cost;
  int size = graph[v].size();
  rep(i, size) {
   ll to_cost = graph[v][i].first;
	 int to = graph[v][i].second;
   if(used[to]) {
    continue;
   }
	 pq.push(make_pair(to_cost, to));
  }
 }
 return;
}

int main() {
  cin >> N >> M;
  graph.resize(N);
  used.resize(N);

  rep(i, M) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    graph[u].push_back(make_pair(c, v));
    graph[v].push_back(make_pair(c, u));
  }

  pq.push(make_pair(0, 0));
  prim();

  cout << ans << endl;
  return 0;
}

