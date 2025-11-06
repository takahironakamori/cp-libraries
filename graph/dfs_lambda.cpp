#include <iostream>
#include <vector>
#include <algorithm>
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


int main() {
  int N, K, X;
  cin >> N >> K >> X;
  vector<string> S(N);
  rep(i, N) {
    cin >> S[i];
  }

  vector<string> ans;

  auto dfs = [&](auto dfs, int cnt, string str) -> void {
    if(cnt == K) {
      ans.push_back(str);
      return;
    }

    rep(i, N) {
      dfs(dfs, cnt+1, str + S[i]);
    }
  };
  dfs(dfs, 0, "");
  
  sort(ans.begin(), ans.end());
  cout<< ans[X-1] << endl;
  return 0;
}