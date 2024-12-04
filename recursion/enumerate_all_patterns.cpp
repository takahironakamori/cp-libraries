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

int N, T;
vector<vector<int>> teams;

void dfs(int pos) {
  if (pos == N) {

    if (teams.size() == T) {
      cout << "---" << endl;
      rep(j, (int) teams.size()) {
        rep(k, (int) teams[j].size()) {
          cout << teams[j][k] << " ";
        }
        cout << endl;
      }
    }

    return;
  }
  int size = teams.size();
  rep(i, size) {
    teams[i].push_back(pos);
    dfs(pos+1);
    teams[i].pop_back();
  }
  teams.push_back({pos});
  dfs(pos+1);
  teams.pop_back();
}


int main() {
  cin >> N >> T;

  dfs(0);
  return 0;
}
