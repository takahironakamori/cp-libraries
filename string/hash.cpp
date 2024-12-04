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


ll mod = 2147483647;
vector<ll> T;
vector<ll> H;
vector<ll> P100;

ll calc_hash(int l, int r) {
  ll res = H[r+1] - (H[l] * P100[r - l + 1] % mod);
  if (res < 0) { res += mod; }
  return res;
}


int main() {
int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> a(Q);
  vector<int> b(Q);
  vector<int> c(Q);
  vector<int> d(Q);
  rep(i, Q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--;
    b[i]--;
    c[i]--;
    d[i]--;
  }

  T.resize(N+1);
  H.resize(N+1);
  P100.resize(N+1);

  // 文字 S を数値に変換
  rep(i, N) {
    T[i+1] = (S[i] - 'a') + 1;
  }

  P100[0] = 1;
  rep(i, N) {
    P100[i+1] = (ll) 100 * P100[i] % mod;
  }

  /*
  cout << endl;
  for(auto i:P100) {
    cout << i << " ";
  }
  cout << endl;
  */

  H[0] = 1;
  rep(i, N) {
    H[i+1] = (ll) (100 * H[i] + T[i+1]) % mod;
  }

  /*
  cout << endl;
  for(auto i:H) {
    cout << i << " ";
  }
  cout << endl;
  */

  rep(i, Q) {
    ll hash1 = calc_hash(a[i], b[i]);
    ll hash2 = calc_hash(c[i], d[i]);
    // cout << hash1 << " " << hash2 << endl;
    if (hash1 == hash2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
