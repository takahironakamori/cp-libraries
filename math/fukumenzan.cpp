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

class Fukumenzan {
	private:
		// 覆面算の文字列を格納した配列
		vector<string> _problem;

		// 計算のための変数
		vector<vector<int>> _board;
		set<int> _used;

		// 未確定であることを表す数字
		const int NOTIN = -1;
	public:
		// コンストラクタ
		Fukumenzan(const vector<string>& input) : _problem(input) {}

		void init() {
			_board.resize(_problem.size());
			rep(i, _problem.size()) {
				_board[i].assign(_problem[i].size(), NOTIN);
			}
			_used.clear();
		}

		// 覆面算全体の行数を返す
		int get_size() const {
			return _problem.size();
		}

		// 覆面算全体の桁数（最下行の桁数）を返す
		int get_digit() const {
			return _problem.back().size();
		}

		// 覆面算の上からrow行目の桁数を返す
		int get_digit(int row) const {
			return _problem[row].size();
		}

		// 数字valがすでに使われているかどうかを返す
		bool is_used(int val) const {
			return _used.count(val);
		}

		// 覆面算の上からrow行目、右からdigit桁目に入れた数字を返す
		int get_val(int row, int digit) const {
			// digit桁目がrow行目の文字列からはみ出す場合は0とする
			if (digit >= get_digit(row)) {
				return 0;
			}
			return _board[row][get_digit(row) - 1 - digit];
		}

		// 覆面算の上からrow行目、右からdigit桁目に入れた数字を返す
		char get_char(int row, int digit) const {
			return _problem[row][get_digit(row) - 1 - digit];
		}

		// 覆面算の計算結果を出力する
		void print() const {
			for(const vector<int>& vec : _board) {
				for(int v: vec) {
					cout << v;
				}
				cout << endl;
			}
		}

		// row行目、右からdigit桁目の文字に数値valを入れる
		void set_val(int row, int digit, int val);

		// row行目、右からdigit桁目の文字に入れていた数字を削除する
		void reset_val(int row, int digit, int val);

		// 覆面文字に入れた数字によって計算が合うかどうかを確認する
		bool is_valid();
};

void Fukumenzan::set_val(int row, int digit, int val) {
	// 該当の文字を求める
	char c = get_char(row, digit);

	// 文字がcであるすべてのマスに数字valを入れる
	rep(i, (int) get_size()) {
		rep(j, (int) get_digit(i)) {
			if(_problem[i][j] == c) {
				_board[i][j] = val;
			}
		}
	}
	_used.insert(val);
}

// row行目、右からdigit桁目の文字に入れていた数字を削除する
void Fukumenzan::reset_val(int row, int digit, int val) {
	// 該当の文字を求める
	char c = get_char(row, digit);

	// 文字がcであるすべてのマスの数字を削除する
	rep(i, (int) get_size()) {
		rep(j, (int) get_digit(i)) {
			if(_problem[i][j] == c) {
				_board[i][j] = -1;
			}
		}
	}
	_used.erase(val);
}

// 覆面文字に入れた数字によって計算が合うかどうかを確認する
bool Fukumenzan::is_valid() {
	// 最上桁に0があってはいけない
	for (const vector<int>& val : _board) {
		if (val[0] == 0) {
			return false;
		}
	}

	// 右から0桁目から順に計算していく
	int kuriagari = 0;
	rep(i, (int) get_digit()) {
		// 右からdigit桁目の、最下行以外の行の和を計算する
		int sum = 0;
		rep(j, (int) get_size()) {
			// まだ数字が入っていない部分に来たらその場で終了する
			if(get_val(j, i) == NOTIN) {
				return true;
			}
			// 最下行以外を足す
			if(j != get_size() - 1) {
				sum += get_val(j, i);
			}
		}
		// 前の桁からの繰り上がりを足して、新たな繰り上がりを計算する
		sum += kuriagari;
		kuriagari = sum / 10;
		// 最下行に来るべき数字（sum % 10）が合っているかを確かめる
		if (sum % 10 != get_val(get_size() - 1, i)) {
			return false;
		}
	}
	// 最後に繰り上がりが残ってはいけない
	if(kuriagari == 0) {
		return true;
	} else {
		return false;
	}
}

// 上からrow行目、右からdigit桁目に数字を入れようとする
void dfs(Fukumenzan& fu, int row, int digit, vector<Fukumenzan>& res) {
	// 終端条件：すべての文字に数字が入ったとき
	if (row == 0 && digit == fu.get_digit()) {
		res.push_back(fu);
		return;
	}

	// 再帰呼び出しのための次のマスを求める
	int next_row = row + 1;
	int next_digit = digit;
	if (next_row == fu.get_size()) {
		next_row = 0;
		next_digit = digit + 1;
	}

	// すでに数字が入っているかどうかで場合分け
	if (fu.get_val(row, digit) != -1) {
		dfs(fu, next_row, next_digit, res);
	} else {
		rep(i, 10) {
			// すでに使用済みの数字は使えない
			if (fu.is_used(i)) {
				continue;
			}
			fu.set_val(row, digit, i);
			if (fu.is_valid()) {
				dfs(fu, next_row, next_digit, res);
			}
			fu.reset_val(row, digit, i);
		}
	}
}

// 覆面算を解く関数
vector<Fukumenzan> solve(Fukumenzan& fu) {
	// 和の桁数が最大でない場合は解なしなので、空の配列を返す
	rep(i, (int) fu.get_size() - 1) {
		if (fu.get_digit(i) > fu.get_digit()) {
			return vector<Fukumenzan>();
		}
	}
	// 初期化する
	fu.init();
	// dfs開始
	vector<Fukumenzan> res;
	dfs(fu, 0, 0, res);
	return res;
}

int main() {
  int N;
	cin >> N;
	vector<string> input(N);
	rep(i, N) {
		cin >> input[i];
	}
	// 再帰的に解く
	Fukumenzan fu(input);
	const vector<Fukumenzan>& res = solve(fu);

	// 出力
	cout << "The num of solutions: " << res.size() << endl;
	rep(i, (int) res.size()) {
		cout << i << " th solution:" << endl;
		res[i].print();
	}
  return 0;
}
