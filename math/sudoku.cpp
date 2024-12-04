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

using Field = vector<vector<int>>;

// 数独を解くためのクラス
class Sudoku {
	private:
		Field _field;
	public:
		// コンストラクタ
		Sudoku() : _field(9, vector<int>(9, - 1)){}

		// fieldデータを返す
		const Field& get(){
			return _field;
		}

		// マス(x,y)に数字valを入れる
		void put(int x, int y, int val){
			_field[x][y] = val;
		}

		// マス(x,y)の数字を削除する
		void reset(int x, int y){
			_field[x][y] = -1;
		}

		// 入力データを受け取る
		void input(){
			rep(i, 9){
				string line;
				cin >> line;
				rep(j, 9) {
					if(line[j] == '*') {
						continue;
					}
					int val = line[j] - '0';
					put(i, j, val);
				}
			}
		}

		// 空きマスを探す
		bool find_empty(int& x, int& y);

		// マス(x,y)に入れられる数字の集合を探す
		vector<int> find_choices(int x, int y);
};

bool Sudoku::find_empty(int& x, int& y) {
	for(x = 0; x < 9; ++x) {
		for(y = 0; y < 9; ++y){
			if (_field[x][y] == -1) {
				return true;
			}
		}
	}
	return false;
}

vector<int> Sudoku::find_choices(int x, int y) {
	set<int> cannot_use;

	rep(i, 9) {
		if(_field[x][i] != -1) {
			cannot_use.insert(_field[x][i]);
		}
	}

	rep(i, 9) {
		if(_field[i][y] != -1) {
			cannot_use.insert(_field[i][y]);
		}
	}

	// 同じブロックに含まれる数字を除外する
	int x2 = x / 3 * 3;
	int y2 = y / 3 * 3;
	for(int i = x2; i < x2 + 3; ++i) {
		for(int j = y2; j < y2 + 3; ++j) {
			if(_field[i][j] != -1) {
				cannot_use.insert(_field[i][j]);
			}
		}
	}

	// マス(x,y)に入れられる数字からなる配列を求める
	vector<int> res;
	for(int i = 1; i <= 9; ++i) {
		if (!cannot_use.count(i)) {
			res.push_back(i);
		}
	}
	return res;
}

void dfs(Sudoku& board, vector<Field>& res, bool all = true) {
	// allがfalseのときは、解を1個求めたら抜ける
	if(!all && !res.empty()) {
		return;
	}
	// 空きマスを探す
	int x, y;
	if(!board.find_empty(x, y)) {
		// 解に追加
		res.push_back(board.get());
		return;
	}

	// マス(x,y)に入れられる数字の集合を求める
	const vector<int>& can_use = board.find_choices(x, y);

	// 空きマス(x,y)に数字を順に入れていく
	for(int val: can_use) {
		board.put(x, y, val);
		dfs(board, res, all);
		board.reset(x, y);
	}
}

// 数独を解く
vector<Field> solve(Sudoku& board, bool all = true) {
	vector<Field> res;
	dfs(board, res, all);
	return res;
}

int main() {
	cout << "Sudoku Input: " << endl;
	Sudoku board;
	board.input();

	vector<Field> res = solve(board);

	if(res.size() == 0) {
		cout << "No Solutions." << endl;
	} else if(1 < res.size()){
		cout << "More than one Solution.";
	} else {
		const Field& ans = res[0];
		rep(i, 9) {
			rep(j, 9) {
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}
  return 0;
}
