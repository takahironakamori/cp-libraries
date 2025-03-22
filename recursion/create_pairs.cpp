#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
// using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

/**
 * createPairs()
 * 0 から N-1 まで（0インデックス）で、
 * 2人組になる組み合わせを全部作る。
 * [v1,v2] としたとき v1 < v2 になる。
 */
int N;
vector<bool> used;
vector<P> pairs;
vector<vector<P>> result;

void createPairs() {
  if ((int)pairs.size() == N / 2) {
    result.push_back(pairs);
    return;
  }
  int l = -1;
  for (int i = 0; i < N; ++i) {
    if (!used[i]) {
      l = i;
      break;
    }
  }
  used[l] = true;
  for (int i = 0; i < N; ++i) {
    if (!used[i]) {
      pairs.push_back({l, i});
      used[i] = true;
      createPairs();
      used[i] = false;
      pairs.pop_back();
    }
  }
  used[l] = false;
}

int main() {
  cin >> N;
  used.resize(N);
  createPairs();

  int n = result.size();
  rep(i, n) {
    for(P item: result[i]) {
      cout << item.first << " " << item.second << endl;
    }
    cout << endl;
  }
  return 0;
}
