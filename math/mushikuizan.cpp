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

// 整数valが文字列strに整合するか
bool is_valid(int64_t val, const string& str) {
	// 整数valを文字列に変換する
	string sval = to_string(val);

	// 整数valの桁数が文字列strの長さに一致する必要がある
	if (sval.size() != str.size()) {
		return false;
	}

	// 1文字ずつ整合性を確認する
	rep(i, (int) sval.size()) {
		// □については不問
		if (str[i] == '*') {
			continue;
		}
		// 一致しない場合はfalse
		if (str[i] != sval[i]) {
			return false;
		}
	}

	return true;
}

// 数字vを文字列strの右からk番目に当てはめたときに整合するかどうか
bool is_valid_sub(int v, int k, const string& str) {
	// 右からk番目の文字を取得する
	char c = str[(int) str.size() - 1 - k];

	// 虫食い場合は問題ない
	if (c == '*') {
		return true;
	}

	// charをintに
	int real_val = c - '0';

	// 数値が一致するかどうかを判定する
	if (v == real_val) {
		return true;
	} else {
		return false;
	}
}

// □に入れた数字から、整数全体を復元する
int64_t decode(const vector<int>& vec){
	int64_t res = 0;
	int64_t order = 1;
	for(int v: vec) {
		res += order * v;
		order *= 10;
	}
	return res;
}

// 虫食算ソルバーを管理するクラス
class Mushikuizan {
	private:
		// 被乗数、乗数、積
		string _multiplicand;
		string _multiplier;
		string _product;

		// 部分積
		vector<string> _middle;

		// 答え
		vector<pair<int64_t, int64_t>> _res;
	public:
		// コンストラクタ
		Mushikuizan(const string& multiplicand,
								const string& multiplier,
								const string& product,
								const vector<string>& middle) :
			_multiplicand(multiplicand), _multiplier(multiplier), _product(product), _middle(middle) {
		}

	// 乗数の□に数字を入れていく再帰関数
	// plicand:被乗数に入れた数字、vec:乗数の□に数字を入れた結果
	void rec_plier(int64_t plicand, vector<int>& vec) {
		// 終端条件:乗数の□のすべてに数字が入ったとき
		if(vec.size() == _multiplier.size()) {
			// 乗数を求める
			int64_t plier = decode(vec);
			// 積の整合性を確認する
			if (!is_valid(plicand * plier, _product)) {
				return;
			}
			// 答えを格納する
			_res.emplace_back(plicand, plier);
			return;
		}

		// 新しい□に数字を入れる（乗数に0は入らないものとする）
		for (int add = 1; add <= 9; ++add) {
			// すでに数字が入っていて矛盾している場合はスキップ
			if (!is_valid_sub(add, vec.size(), _multiplier)) {
				continue;
			}
			// □に数字addを入れて整合性を確認する
			if (!is_valid(plicand * add, _middle[vec.size()])) {
				continue;
			}
			// vecに数字addを加えて再帰呼び出し
			vec.push_back(add);
			rec_plier(plicand, vec);
			vec.pop_back();
		}
	}

	// 被乗数の□に数字を入れていく関数
	// vec:被乗数の□に数字を入れた結果
	void rec_plicand(vector<int>& vec) {
		// 終端条件：被乗数の□のすべてに数字が入ったとき
		if (vec.size() == _multiplicand.size()) {
			// 今度は乗数の□に数字を入れていく
			vector<int> vec2;
			rec_plier(decode(vec), vec2);
			return;
		}

		// 新しい□に数字を入れる
		for(int add = 0; add <= 9; ++add) {
			// 左端に0は入れられない
			if (vec.empty() && add == 0) {
				continue;
			}
			// すでに数字が入っていて矛盾している場合はスキップ
			if (!is_valid_sub(add, vec.size(), _multiplicand)) {
				continue;
			}
			// vecに数値addを加えて再帰呼び出し
			vec.push_back(add);
			rec_plicand(vec);
			vec.pop_back();
		}
	}

	// 虫食算を解く（被乗数と乗数のペアを格納した配列を返す）
	vector<pair<int64_t, int64_t>> solve() {
		// 答えを表す配列を空にする
		_res.clear();
		// 被乗数の□のほうから数字を入れていく
		vector<int> vec;
		rec_plicand(vec);
		return _res;
	}
};

int main() {
	int A, B;
	cin >> A >> B;
	string hijou, jou, seki;
	vector<string> middle(B);
	cin >> hijou >> jou;
	rep(i, B) {
		cin >> middle[i];
	}
	cin >> seki;

	// 再帰的に解く
	Mushikuizan mu(hijou, jou, seki, middle);
	const vector<pair<int64_t, int64_t>>& res = mu.solve();

	// 解を出力
	cout << "The num of solutions: " << res.size() << endl;
	rep(i, (int) res.size()) {
		cout << i << " th solution: " << res[i].first << " * " << res[i].second << " = " << res[i].first * res[i].second << endl;
	}
	return 0;
  return 0;
}
