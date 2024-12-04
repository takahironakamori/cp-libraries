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

const int EMPTY = 0;
const int PLUS = 1;
const int MINUS = 2;
const int MUL = 3;
const int DIV = 4;

int V;

// 空白を処理
pair<vector<double>, vector<int>> calc_empty(vector<int>& v) {

	//処理後の計算式を表すデータ
	vector<double> new_vals;
	vector<int> new_signs;

	// 途中経過の値（最初は1）
	double val = 1;

	// 演算子を順番に見ていく
	rep(i, v.size()) {

		double add = i + 2;

		// 空白の場合は、数値を連結する
		// 空白じゃない場合は、数値と演算子の組を新たに記録する
		if (v[i] == EMPTY) {
			val = val * 10 + add;
		} else {
			new_vals.push_back(val);
			new_signs.push_back(v[i]);
			val = add;
		}
	}

	// 最後の値を加える
	new_vals.push_back(val);
	return make_pair(new_vals, new_signs);
}


// 掛け算、割り算を処理
pair<vector<double>, vector<int>> calc_mul_div(vector<double>& v, vector<int>& signs) {

	// 処理後の計算式を表すデータ
	vector<double> new_vals;
	vector<int> new_signs;

	// 途中経過の値
	double val = v[0];

	// 演算子を順番に見ていく
	rep(i, signs.size()) {

		double add = v[i + 1];

		// 掛け算、割り算の場合は、計算する
		// それ以外の場合は、数値と演算子の組を新たに記録する
		if (signs[i] == MUL) {
			val *= add;
		} else if(signs[i] == DIV) {
			val /= add;
		} else {
			new_vals.push_back(val);
			new_signs.push_back(signs[i]);
			val = add;
		}
	}

	// 最後の値を加える
	new_vals.push_back(val);
	return make_pair(new_vals, new_signs);
}


// 足し算、引き算を処理
double calc_plus_minus(vector<double>& v, vector<int>& signs) {;

	// 答え
	double val = v[0];

	// 演算子を順番に見ていく
	rep(i, signs.size()) {

		double add = v[i + 1];

		// 足し算か引き算の場合は、計算する
		if (signs[i] == PLUS) {
			val += add;
		} else if(signs[i] == MINUS) {
			val -= add;
		}
	}

	return val;
}


double calc(vector<int>& v) {

	// 空白を連結
	pair<vector<double>, vector<int>> step1 = calc_empty(v);

	// 掛け算と割り算
	pair<vector<double>, vector<int>> step2 = calc_mul_div(step1.first, step1.second);

	// 足し算と引き算
	return calc_plus_minus(step2.first, step2.second);

}

string decode(vector<int>& v) {
	string res = "1";
	rep(i, v.size()) {
		if (v[i] == PLUS) {
			res += " + ";
		} else if (v[i] == MINUS) {
			res += " - ";
		} else if (v[i] == MUL) {
			res += " * ";
		} else if (v[i] == DIV) {
			res += " / ";
		}
		res += to_string(i + 2);
	}
	return res;
}

void rec(vector<int>& v, vector<string>& res) {
	if (v.size() == 8) {
		double exp = 1e-9;
		if (abs(calc(v) - V) < exp){
			res.push_back(decode(v));
		}
		return;
	}

	for(int add = 0; add < 5; ++add) {
		vector<int> v2 = v;
		v2.push_back(add);
		rec(v2, res);
	}
}

int main() {
  cin >> V;

	vector<int> v;

	vector<string> res;
	rec(v, res);

	cout << res.size() << endl;
	rep(i, res.size()) {
		cout << res[i] << " = " << V << endl;
	}
  return 0;
}
