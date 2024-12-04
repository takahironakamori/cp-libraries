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
* 逆ポーランド記法で表された計算式を通常の計算式に戻す関数
*
* @param string str 計算式
* @return string 結果
*/
string decode_poland(const string& str) {

	// 計算のための配列
	vector<string> v;

	// 逆ポーランド記法の各文字を順番に調べる
	rep(i, (int) str.size()) {

		char c = str[i];

		// c が数字の場合は int に変換して配列の末尾に足す
		// c が演算子の場合は、v から数値をとって計算する
		if ('0' <= c && c <= '9') {
			v.push_back({c});
		} else {
			string s2 = v.back();
			v.pop_back();
			string s1 = v.back();
			v.pop_back();

			// 乗算と除算の場合、前後に(  )をつける
			if (c == '*' || c == '/') {
				if (1 < s1.size()) {
					s1 = "(" + s1 + ")";
				}
				if (1 < s2.size()) {
					s2 = "(" + s2 + ")";
				}
			}
			switch(c) {
				case '+':
					v.push_back(s1 + "+" + s2);
					break;
				case '-':
					v.push_back(s1 + "-" + s2);
					break;
				case '*':
					v.push_back(s1 + "*" + s2);
					break;
				case '/':
					v.push_back(s1 + "/" + s2);
					break;
			}
		}
	}
	return v.back();
}

int main() {

  // 1 + 2 + 3 + 4 = ?
	string s1 = "12+3+4+";
	cout << decode_poland(s1) << endl;

	// 7 + 5 - 3 + 1 = ?
	string s2 = "75+3-1+";
	cout << decode_poland(s2) << endl;

	// 1 * 1 * 2 * 5 = ?
	string s3 = "11*2*5*";
	cout << decode_poland(s3) << endl;

	// 1 + 1 + 2 * 4 = ?
	string s4 = "11+24*+";
	cout << decode_poland(s4) << endl;

	// (1 + 1) * (6 - 1) = ?
	string s5 = "11+61-*";
	cout << decode_poland(s5) << endl;

	// (7 - 1) / 2 + 7 = ?
	string s6 = "71-2/7+";
	cout << decode_poland(s6) << endl;

	// 5 * 7 - 5 * 5 = ?
	string s7 = "57*55*-";
	cout << decode_poland(s7) << endl;

	// (9 * 9 + 9) / 9 = ?
	string s8 = "99*9+9/";
	cout << decode_poland(s8) << endl;

	// (1 + 7 / 3) * 3 = ?
	string s9 = "173/+3*";
	cout << decode_poland(s9) << endl;

	// (1 + 1 / 9) * 9 = ?
	string s10 = "119/+9*";
	cout << decode_poland(s10) << endl;

	// 8 / (1 - 1 / 5) = ?
	string s11 = "8115/-/";
	cout << decode_poland(s11) << endl;

	// (3 - 7 / 4) * 8 = ?
	string s12 = "374/-8*";
	cout << decode_poland(s12) << endl;

  return 0;
}
