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
const int INF = 1001001001;

struct Edge {
	int to, cost;
};

int main() {
  int N, M, K;
	cin >> N >> M >> K;

	vector<vector<Edge>> graph(N);

	rep(i, M) {
		int u, v, a;
		cin >> u >> v >> a;
		u--;
		v--;
		Edge e1;
		e1.to = v;
		e1.cost = 1;
		graph[u].push_back(e1);
		Edge e2;
		e2.to = u;
		e2.cost = 1;
		graph[v].push_back(e2);
	}

	vector<int> dist(N, INF);
	deque<P> q;
	dist[0] = 0;
	q.emplace_back(0,0);

	while(!q.empty()) {
		P p = q.front();
		q.pop_front();
		int cost_ = p.first;
		int to_ = p.second;
		if (dist[to_] != cost_) { continue; }
		for(Edge e: graph[to_]) {
			int nd = cost_ + e.cost;
			if (dist[e.to] <= nd) { continue; }
			dist[e.to] = nd;
			if (e.cost == 1) {
				q.emplace_back(nd, e.to);
			} else {
				q.emplace_front(nd, e.to);
			}
		}
	}

	int ans = dist[N - 1];
	if (ans == INF) { ans = -1; }
	cout << ans << endl;  
  return 0;
}
