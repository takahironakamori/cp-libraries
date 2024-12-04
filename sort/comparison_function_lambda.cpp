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
  vector<ll> A(N);
  vector<ll> B(N);
  vector<int> idx(N);
  rep(i, N) {
    cin >> A[i] >> B[i];
    idx[i] = i;
  }

  sort(idx.begin(), idx.end(), [&](int l, int r){
    if(A[l] * (A[r]+B[r]) != A[r] * (A[l] + B[l])) {
      return A[l] * (A[r]+B[r]) > A[r] * (A[l] + B[l]);
    } else {
      return l < r;
    }
  });

  rep(i, N) {
    cout << idx[i]+1<< " ";
  }
  cout << endl;
  return 0;
}
