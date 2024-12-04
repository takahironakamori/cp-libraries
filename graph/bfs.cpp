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

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> graph(N);
  vector<int> dist(N, INF);

  rep(i, M) {
    int A, B;
    cin >> A >> B;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }

  queue<int> que;
  que.push(0);
  dist[0] = 0;

  while(!que.empty()) {
    int c = que.front();
    que.pop();
    int d = dist[c];

    vector<int> children = graph[c];
    int n = children.size();
    for(int i = 0; i < n; ++i) {
      int t = children[i];
      if(dist[t] == INF) {
        dist[t] = d + 1;
        que.push(t);
      }
    }
  }

  int ans = 0;
  rep(i, N) {
    ans = max(ans, dist[i]);
  }
  cout << ans << endl;
  return 0;
}
