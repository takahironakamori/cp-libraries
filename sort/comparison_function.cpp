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

// 比較関数
bool cmp(const P& a, const P& b) {
  if(a.first < b.first) {
    return true;
  }
  if(a.first > b.first) {
    return false;
  }
  if(a.second < b.second) {
    return true;
  }
  if(a.second > b.second) {
    return false;
  }
  return false;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<P> AB(M);
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    AB[i] = make_pair(A, B);
  }

  sort(AB.begin(), AB.end(), cmp);

  rep(i, M) { cout << AB[i].first << ":" << AB[i].second << endl; }
  return 0;
}
