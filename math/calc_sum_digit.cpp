#include <iostream>
#include <vector>
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

  // xの各桁の和を返す
  auto f = [&](int x) -> int{
    int res = 0;
    while(x) {
      res += x % 10;
      x /= 10;
    }
    return res;
  };

  return 0;
}