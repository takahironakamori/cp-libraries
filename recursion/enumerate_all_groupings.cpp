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

/**
 * N人 をグループに分けた時の全パターン列挙
 * N = 12 のとき 4213597 パターン
 */
int N;
void dfs(int i, vector<vector<int>> groups) {
  if(i == N) {
    return;
  }
  
  // 既存のグループに加える
  rep(j, ((int) groups.size())) {
    groups[j].push_back(i);
    dfs(i+1, groups);
    groups[j].pop_back();
  }

  // 新しいグループを作る
  groups.push_back(vector<int>(1, i));
  dfs(i+1, groups);
}

int main() {
  cin >> N;

  dfs(0, {});
  return 0;
}
