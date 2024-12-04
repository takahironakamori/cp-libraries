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

int bubbleSort(vector<int> &v) {
  int res = 0;
  for(int i = 0; i < (int) v.size() - 1; i++) {
    for(int j = 0; j < (int) v.size() - 1; j++) {
      if(v[j + 1] < v[j]) {
        swap(v[j], v[j + 1]);
        res++;
      }
    }
  }
  return res;
}

int main() {
  vector<int> v = { 43, 5, 123, 94, 359, -23, 2, -1 };
 
  for(auto i:v) {
    cout << i << " ";
  }
  cout << endl;
 
  bubbleSort(v);
 
  for(auto i:v) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
