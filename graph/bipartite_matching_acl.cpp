#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
// using mint =　modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

// ACL MaxFlow
// https://atcoder.github.io/ac-library/production/document_ja/maxflow.html

int main() {
  int N;
  cin >> N;

  mf_graph<int> graph((2 * N) + 2);

  rep(i, N) {
    string c;
    cin >> c;
    rep(j, N) {
      if (c[j] == '#') {
        graph.add_edge(i + 1, N + j + 1, 1);
      }
    }
  }

  rep(i, N) {
    graph.add_edge(0, i + 1, 1);
    graph.add_edge(N + i + 1, 2 * N + 1, 1);
  }

  cout << graph.flow(0, 2 * N + 1) << endl;
  return 0;
}
