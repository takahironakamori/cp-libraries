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
vector<int> cntSelfLoop; // 自己ループの辺の数
int cntV; // 頂点の数
int cntE; // 辺の数

void dfs(int c) {
  visited[c] = true;
  cntV++;
  cntE += cntSelfLoop[c];
  for(auto n:graph[c]) {
    if (c < n) {
      cntE++;
    }
    if(!visited[n]) {
      dfs(n);
    }
  }
}

int main() {
  cin >> N >> M;
  graph.resize(N);
  visited.resize(N);
  cntSelfLoop.resize(N);

  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if(a == b) {
      cntSelfLoop[a]++;
    } else {
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
  }

  rep(i, N) {
    if(visited[i]) {
      continue;
    }
    cntE = 0;
    cntV = 0;
    dfs(i);
    cout << i + 1 << "が属する連結成分の頂点数 : " << cntV << ", 辺の数 : " << cntE << endl;
  }

  return 0;
}
