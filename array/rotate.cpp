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

/*
4
aaa
bbb
ccc
ddd
*/

// 時計回りに 90 度回す(H * W を W * H に変える)
// v は H 行 W 列の配列
vector<string> rotate90(vector<string>& v) {
  int h = v.size();
  int w = v[0].size();
  vector<string> res(w);
  rep(i, w) {
    string _s = "";
    rep(j, h) {
      _s += v[h - (j + 1)][i];
    }
    res[i] = _s;
  }
  return res;
}

// 時計回りに 180 度回す(N * Nのみ)
vector<string> rotate180(vector<string>& v) {
  int n = v.size();
  vector<string> res(n);
  rep(i, n) {
    string _s = "";
    int m = v[i].size();
    rep(j, m) {
      _s += v[n - (i + 1)][m - (j + 1)];
    }
    res[i] = _s;
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

  vector<string> v1 = rotate90(S);

  cout << endl;
  rep(i, (int) v1.size()) {
    rep(j, (int) v1[i].size()) {
      cout << v1[i][j];
    }
    cout << endl;
  }
  cout << endl;

  vector<string> v2 = rotate90(v1);

  rep(i, (int) v2.size()) {
    rep(j, (int) v2[i].size()) {
      cout << v2[i][j];
    }
    cout << endl;
  }
  cout << endl;

  vector<string> v3 = rotate90(v2);

  rep(i, (int) v3.size()) {
    rep(j, (int) v3[i].size()) {
      cout << v3[i][j];
    }
    cout << endl;
  }
  cout << endl;

  vector<string> v5 = rotate180(S);

  rep(i, (int) v5.size()) {
    rep(j, (int) v5[i].size()) {
      cout << v5[i][j];
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
