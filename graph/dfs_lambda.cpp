#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, ll>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
// using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int>> graph(N);
  rep(i, N-1) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  vector<int> V(K);
  rep(i, K) {
    cin >> V[i];
    V[i]--;
  }

  vector<bool> visited(N);
  rep(i, K) {
    visited[V[i]] = true;
  }

  vector<int> cnt(N);
  auto dfs = [&](auto dfs, int v, int p) -> void {
    if(visited[v]) {
      cnt[v]++;
    }
    for(int i:graph[v]) {
      if(i == p) {
        continue;
      }
      dfs(dfs, i, v);
      cnt[v] += cnt[i];
    }
  };
  dfs(dfs, V[0], -1);

  int ans = 0;
  rep(i, N) {
    if(0 < cnt[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
