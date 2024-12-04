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

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  int mx = 0;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    mx = max(mx, A[i]);
  }

  vector<int> check(mx + 1);

  for (int i = 0; i < N; ++i) {
    int current = A[i];
    for (int j = current; j <= mx; j += current) {
      check[j]++;
    }
  }
  return 0;
}
