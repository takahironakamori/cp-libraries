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
* @param string str 計算式
* @return double 結果
*/
double calc_poland(const string& str) {

	// 計算のための配列
	vector<double> v;

	// 逆ポーランド記法の各文字を順番に調べる
	rep(i, (int) str.size()) {

		char c = str[i];

		// c が数字の場合は int に変換して配列の末尾に足す
		// c が演算子の場合は、v から数値をとって計算する
		if ('0' <= c && c <= '9') {
			int n = c - '0';
			v.push_back(n);
		} else {
			double d2 = v.back();
			v.pop_back();
			double d1 = v.back();
			v.pop_back();

			switch(c) {
				case '+':
					v.push_back(d1 + d2);
					break;
				case '-':
					v.push_back(d1 - d2);
					break;
				case '*':
					v.push_back(d1 * d2);
					break;
				case '/':
					v.push_back(d1 / d2);
					break;
			}
		}
	}
	return v.back();
}

int main() {

  // 1 + 2 + 3 + 4 = ?
	string s1 = "12+3+4+";
	cout << calc_poland(s1) << endl;

	// 7 + 5 - 3 + 1 = ?
	string s2 = "75+3-1+";
	cout << calc_poland(s2) << endl;

	// 1 * 1 * 2 * 5 = ?
	string s3 = "11*2*5*";
	cout << calc_poland(s3) << endl;

	// 1 + 1 + 2 * 4 = ?
	string s4 = "11+24*+";
	cout << calc_poland(s4) << endl;

	// (1 + 1) * (6 - 1) = ?
	string s5 = "11+61-*";
	cout << calc_poland(s5) << endl;

	// (7 - 1) / 2 + 7 = ?
	string s6 = "71-2/7+";
	cout << calc_poland(s6) << endl;

	// 5 * 7 - 5 * 5 = ?
	string s7 = "57*55*-";
	cout << calc_poland(s7) << endl;

	// (9 * 9 + 9) / 9 = ?
	string s8 = "99*9+9/";
	cout << calc_poland(s8) << endl;

	// (1 + 7 / 3) * 3 = ?
	string s9 = "173/+3*";
	cout << calc_poland(s9) << endl;

	// (1 + 1 / 9) * 9 = ?
	string s10 = "119/+9*";
	cout << calc_poland(s10) << endl;

	// 8 / (1 - 1 / 5) = ?
	string s11 = "8115/-/";
	cout << calc_poland(s11) << endl;

	// (3 - 7 / 4) * 8 = ?
	string s12 = "374/-8*";
	cout << calc_poland(s12) << endl;

  return 0;
}
