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
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
  }

  // upper_boundのイテレータから先頭のイテレータを引くと
  // K < A[x] を満たす x の最小値を求めることができる。
  // それは、K 以下の小さい要素の個数と言うこともできる。
  int v = upper_bound(A.begin(), A.end(), K) - A.begin();
  cout << v << endl;
  
  
  vector<int> B = {100, 200, 300, 300, 400, 400, 500};

  int test1 = upper_bound(B.begin(), B.end(), 0) - B.begin();
  cout << test1 << endl; // 0 -> B[0] = 100

  int test2 = upper_bound(B.begin(), B.end(), 200) - B.begin();
  cout << test2 << endl; // 2 -> B[2] = 300

  int test3 = upper_bound(B.begin(), B.end(), 400) - B.begin();
  cout << test3 << endl; // 6 -> B[6] = 500

  int test4 = upper_bound(B.begin(), B.end(), 500) - B.begin();
  cout << test4 << endl; // 7 -> B[7] はない

  int test5 = upper_bound(B.begin(), B.end(), 600) - B.begin();
  cout << test5 << endl; // 7 -> B[7] はない

  // 400以下は何個あるか？
  int test6 = upper_bound(B.begin(), B.end(), 400) - B.begin();
  cout << test6 << endl; // 6個

  // 300超は何個あるか
  int test7 = B.end() - upper_bound(B.begin(), B.end(), 300);
  cout << test7 << endl; // 3個

  return 0;
}
