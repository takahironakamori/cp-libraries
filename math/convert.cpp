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

//n 進数（ll）の文字列 v を10進数に変換する
ll f1(string v, int n) {
  ll res = 0;
  rep(i, int(v.size())) res = res * n + int(v[i] - '0');
  return res;
}

// ll v を n 進数(文字列)に変換する
string f2(ll v, int n) {
  if(v == 0) {
    return "0";
  }
  string res = "";
  /*
  while(0 < v) {
    res = to_string(v % n) + res;
    v = v / n;
  }
  */
  while(v) {
    res += static_cast<char>('0' + static_cast<int>(v % n));
    v /= n;
  }
  return res;
}

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  // N進数のSを10進数に変換する
  ll res = f1(S, N);

  // 10進数をK進数にする
  string ans = f2(res, K);

  cout << ans << endl;
  
  return 0;
}
