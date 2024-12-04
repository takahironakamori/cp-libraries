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

// 配列の余分な . を取り除く
// 
// 例
//  ....      ##
//  .##.      #.
//  .#..  =>  .#
//  ..#.
//  ....
// 
vector<string> shapeUpArray(vector<string>& v) {
  int n = v.size();
  int m = v[0].size();
  int minX = m;
  int minY = n;
  int maxX = 0;
  int maxY = 0;
 
  rep(i, n) {
    rep(j, m) {
      if (v[i][j] == '#') {
        minX = min(minX, j);
        minY = min(minY, i);
        maxX = max(maxX, j);
        maxY = max(maxY, i);
      }
    }
  }
 
  vector<string> res;
  for(int i = minY; i <= maxY; ++i) {
    string r = "";
    for(int j = minX; j <= maxX; ++j) {
      r += v[i][j];
    }
    res.push_back(r);
  }
  return res;
}

int main() {
  int N;
  cin >> N;

  vector<string> S(N);
  rep(i, N) {
    cin >> S[i];
  }


  vector<string> v1 = shapeUpArray(S);

  int n = v1.size();
  rep(i, n) {
    int m = v1[i].size();
    rep(j, m) {
      cout << v1[i][j];
    }
    cout << endl;
  }

  return 0;
  return 0;
}
