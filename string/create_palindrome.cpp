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
  ll N;
  cin >> N;

  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  N--;

  for (int keta = 1;; keta++) {
    int l = (keta + 1) / 2;
    ll num = 9;
    rep(i, l-1) {
      num *= 10;
    }
    if (num < N) {
      N -= num;
      continue;
    }

    N += num / 9 - 1;
    string s = to_string(N);
    string s2 = s;
    reverse(s2.begin(), s2.end());
    if (keta % 2 == 1) {
      s.pop_back();
    }
    s += s2;
    cout << s << endl;
    return 0;
  }
  return 0;
}
