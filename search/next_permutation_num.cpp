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

  vector<int> v;

  for(int i = 0; i < N; i++) {
    v.push_back(i + 1);
  }

  // 1からNまでの順列を生成し、出力する
  do {
    for(int i = 0; i < N; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  } while(next_permutation(v.begin(), v.end()));
  
  return 0;
}
