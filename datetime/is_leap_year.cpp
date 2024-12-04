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

// yyyy 年がうるう年か否かを返す
bool isLeapYear(int yyyy) {
  if(yyyy % 4 == 0) {
    if(yyyy % 100 == 0) {
      if(yyyy % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
  } else {
    return false;
  }
  return false;
}

int main() {

  bool flg = isLeapYear(2020);

  return 0;
}
