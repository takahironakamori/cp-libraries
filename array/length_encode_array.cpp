#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, string>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
// using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 62;
// const int INF = 1001001001;

// 連長圧縮する
// {a,a,a,a,b,b,b,c,c,d,a,a} -> {{a,4},{b,3},{c,2},{d,1},{a,2}}
vector<pair<string, int>> lengthEncodeArray(vector<int>& v) {
  vector<pair<string, int>> res;
  int len = (int) v.size();
  rep(i, len) {
    string current = to_string(v[i]);
    int cnt = 1;

    while(i + 1 < len && v[i] == v[i + 1]) {
      cnt++;
      i++;
    }
    res.push_back(make_pair(current, cnt));
  }
  return res;
}


int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) {
		cin >> A[i];
	}

	vector<pair<string, int>> res = lengthEncodeArray(A);
	int ans = 0;
	for(auto i:res) {
		ans += i.second / 2;
	}
	cout << ans << endl;
  return 0;
}
