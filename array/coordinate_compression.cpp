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

// 配列を圧縮して返す
vector<ll> coordinateCompression(vector<ll> &v) {

  set<ll> st;
  for(auto i: v) { st.insert(i); }

  int index = 0;
  map<ll, ll> mp;
  for(auto i : st) {
    mp[i] = index;
    index++;
  }

  vector<ll> res;
  for(auto i: v) {
    res.push_back(mp[i]+1);
  }
  return res;
}

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
  }

  vector<ll> ans = coordinateCompression(A);

  for(auto i: ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
