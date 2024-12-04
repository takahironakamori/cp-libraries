#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
// using mint = modint1000000007;
const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

struct Matrix {
  vector<vector<ll>> p;
  Matrix() {
    p.resize(2, vector<ll>(2, 0));
  }
};

// 2 x 2 行列 A, B の積を返す
Matrix f(Matrix A, Matrix B) {
  Matrix result;
  rep(i, 2) {
    rep(k, 2) {
      rep(j, 2) {
        result.p[i][j] += A.p[i][k] * B.p[k][j];
        result.p[i][j] %= mod;
      }
    }
  }
  return result;
}

// A の n 乗を返す
Matrix f2(Matrix A, ll n) {
  Matrix P = A;
  Matrix Q;
  bool flg = false;
  rep(i, 60) {
    if((n & (1LL << i)) != 0LL) {
      if(flg == false) {
        Q = P;
        flg = true;
      } else {
        Q = f(Q, P);
      }
    }
    P = f(P, P);
  }
  return Q;
}

int main() {
  ll N;
  cin >> N;

  Matrix A;
  A.p[0][0] = 1;
  A.p[0][1] = 1;
  A.p[1][0] = 1;

  Matrix B = f2(A, N - 1);

  cout << (B.p[1][0] + B.p[1][1]) % mod << endl;

  return 0;
}
