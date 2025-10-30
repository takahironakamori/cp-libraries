#include <iostream>
#include <set>
#include <algorithm>
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


// start <= end までの回文数（10進法, string）を作る
set<string> createPalindromicNumbers(ll start, ll end) {
  set<string> st;
  for (ll i = start; i < end; i++) {
    string s = to_string(i);
    string s2 = s;
    reverse(s2.begin(), s2.end());
    s += s2;
    st.insert(s);
    s.erase(s.begin()+(s.size()/2));
    st.insert(s);
  }
  return st;
}


int main() {
  set<string> st = createPalindromicNumbers(1, 100);
  for(auto item:st) {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}