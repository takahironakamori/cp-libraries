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
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int current) {
  if (visited[current]) {
    return;
  }
  visited[current] = true;
  int n = graph[current].size();
  rep(i, n) {
    int nxt = graph[current][i];
    dfs(nxt);
  }
}

int main() {
  cin >> N >> M;

  graph.resize(N);
  visited.resize(N);

  rep(i, N) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    graph[A].push_back(B);
  }

  ll ans = 0;

  rep(i, N) {
    rep(j, N) {
      visited[j] = false;
    }
    dfs(i);
    rep(j, N) {
      if (visited[j]) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
