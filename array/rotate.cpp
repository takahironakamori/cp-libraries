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

// 時計回りに 90 度回す(N * Nのみ)
vector<string> rotate90(vector<string>& v) {
  int n = v.size();
  vector<string> res(n);
  rep(i, n) {
    string _s = "";
    int m = v[i].size();
    rep(j, m) {
      _s += v[m - (j + 1)][i];
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

  rep(i, N) {
    int M = v1[i].size();
    rep(j, M) {
      cout << v1[i][j];
    }
    cout << endl;
  }


  vector<string> v2 = rotate90(v1);

  rep(i, N) {
    int M = v2[i].size();
    rep(j, M) {
      cout << v2[i][j];
    }
    cout << endl;
  }


  vector<string> v3 = rotate90(v2);

  rep(i, N) {
    int M = v3[i].size();
    rep(j, M) {
      cout << v3[i][j];
    }
    cout << endl;
  }


  vector<string> v5 = rotate180(S);

  rep(i, N) {
    int M = v5[i].size();
    rep(j, M) {
      cout << v5[i][j];
    }
    cout << endl;
  }
  return 0;
}
