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

// ニム和（配列全て XOR した値）
int nim_sum(vector<int> &v) {
  int s = v.size();
  int res = v[0];
  for(int i = 1; i < s; ++i) {
    res ^= v[i];
  }
  return res;
}

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i, N) { cin >> A[i]; }

  int sum = nim_sum(A);
  
  cout << sum << endl;
  return 0;
}
