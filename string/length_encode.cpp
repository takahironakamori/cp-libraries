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

// 連長圧縮する
// aaaabbbccdaa -> {{a,4},{b,3},{c,2},{d,1},{a,2}}
vector<pair<char, int>> lengthEncode(string& str) {
  vector<pair<char, int>> res;
  int len = (int) str.size();
  rep(i, len) {
    char current = str[i];
    int cnt = 1;

    while(i + 1 < len && str[i] == str[i + 1]) {
      cnt++;
      i++;
    }
    res.push_back(make_pair(current, cnt));
  }
  return res;
}

int main() {
  string S;
  cin >> S;

  vector<pair<char, int>> res = lengthEncode(S);
  rep(i, (int) res.size()) {
    cout << res[i].first << " " << res[i].second << " ";
  }
  cout << endl;
  return 0;
}
