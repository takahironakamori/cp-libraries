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

/**
* 逆ポーランド記法で表された計算式を計算する関数
*
* @param vector<string> vec 計算式
* @return double 結果
*/
double calc_poland(const vector<string>& vec) {

	// 計算のための配列
	deque<double> v;

	// 逆ポーランド記法の各文字を順番に調べる
	rep(i, (int) vec.size()) {

		if(vec[i] == "+" || vec[i] == "-" || vec[i] == "*" || vec[i] == "/") {
      double d2 = v.back();
			v.pop_back();
			double d1 = v.back();
			v.pop_back();

			if(vec[i] == "+") {
				v.push_back(d1 + d2);
      } else if(vec[i] == "-") {
        v.push_back(d1 - d2);
      } else if(vec[i] == "*") {
				v.push_back(d1 * d2);
      } else if(vec[i] == "/") {
				v.push_back(d1 / d2);
			}
    } else {
      int v2 = stoi(vec[i]);
      v.push_back((double) v2 - 0.0);
    }
	}
	return v.back();
}

int main() {

  // 1 + 2 + 3 + 4 = ?
	string s1 = "12+3+4+";
  vector<string> v1;
  rep(i, (int) s1.size()) {
    v1.push_back(string(1, s1[i]));
  }
	cout << calc_poland(v1) << endl;

  return 0;
}
