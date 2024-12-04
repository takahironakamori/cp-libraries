#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
// using mint = modint998244353;
// const int mod = 998244353;
// using mint = modint1000000007;
// const int mod = 1000000007;
// const ll INF = 1LL << 60;
// const int INF = 1001001001;

// ==============================
// struct
// ==============================

struct State {
  int score;
  int x[29];
  char last;
  int from;
};


// ==============================
// 変数
// ==============================

// true:ビジュアライザ用 false:提出用
bool isLocal;

// 入力データ
vector<string> inputs;

// inputファイル名
string inputFileName = "";

// 入力
int T;
vector<int> p(109);
vector<int> q(109);
vector<int> r(109);

// 配列 X の数
int N = 20;

// 答え
vector<char> ans(101);

// ビーム幅
int width = 10000;

// 状態数 cntState[i] := i 手目時点での状態数 (<= width)
vector<int> cntState(109);

// 結果を保持
vector<vector<State>> beam(109, vector<State>(width));


// ==============================
// ライブラリ関数
// ==============================

// 指定したtxtファイルを読み込む（ビジュアライザ用）
vector<string> importFile(string name) {
  vector<string> result;
  string filename(name);
  string line;
  ifstream input_file(filename);
  if(!input_file.is_open()) {
    cout << "Could not open the file" << endl;
    return result;
  }
  while(getline(input_file, line)) {
    result.push_back(line);
  }
  return result;
}

// txtファイルに出力する（ビジュアライザ用）
void outputFile(string s) {
  ofstream outputfile("output.txt", ios::app);
	outputfile << s << "\n";
  outputfile << flush;
  outputfile.close();
}

// start から end までの入力データを試す
void loadInputFiles(int start, int end) {
	if (end < start) {
		swap(start, end);
	}
	for (int i = start; i < end + 1; i++){
		string s = to_string(i);
		string fileName = "in/";
		int l = 4 - s.size();
		rep(j, l) {
			fileName += "0";
		}
		fileName += s;
		fileName += ".txt";
		inputFileName = fileName;
	}
}

// 文字列を指定した文字で区切る
vector<string> stringSplit(const string& str, char sep) {
  vector<string> v;
  stringstream ss(str);
  string buffer;
  while(getline(ss, buffer, sep)) {
    v.push_back(buffer);
  }
  return v;
}

// start 以上、end 以下でランダムなintを返す
random_device rd;
default_random_engine eng(rd());
int generateRandom(int start, int end) {
  uniform_real_distribution<double> distr(start - 1, end);
  return ceil(distr(eng));
}

// 点 p1 と点 p2 の距離を返す
double calc_dist(P p1, P p2) {
  double distX = p1.first - p2.first;
  double distY = p1.second - p2.second;
  double result = sqrt(distX * distX + distY * distY);
  return result;
}


// ==============================
// 関数
// ==============================

// 初期設定
void init() {

	// 入力を受け取る
  if(isLocal) {
  	loadInputFiles(0, 0);
		ofstream outputfile("output.txt");
    outputfile << flush;
    outputfile.close();
    inputs = importFile(inputFileName);
    vector<string> s = stringSplit(inputs[0], ' ');
    T = stoi(s[0]);
  } else {
    cin >> T;
  }

  if (isLocal) {
    rep(i, T) {
      vector<string> s = stringSplit(inputs[i+1], ' ');
      p[i+1] = stoi(s[0]);
      q[i+1] = stoi(s[1]);
      r[i+1] = stoi(s[2]);
    }
  } else {
    rep(i, T) {
      cin >> p[i+1] >> q[i+1] >> r[i+1];
    }
  }
}


// 比較関数
bool cmp(const State& a, const State& b) {
  if(a.score > b.score) {
    return true;
  }
  return false;
}


// ==============================
// ビームサーチ
// ==============================

void beamSearch() {
  // 0 手目の状態を設定
  cntState[0] = 1;
  beam[0][0].score = 0;
  rep(i, N) {
    beam[0][0].x[i+1] = 0;
  }

  // ビームサーチ
  for(int i = 1; i <= T; ++i){
    vector<State> c;
    for(int j = 0; j < cntState[i-1]; ++j) {
      // 操作 A
      State actionA = beam[i-1][j];
      actionA.last = 'A';
      actionA.from = j;
      actionA.x[p[i]] += 1;
      actionA.x[q[i]] += 1;
      actionA.x[r[i]] += 1;
      for(int k = 1; k <= N; ++k) {
        if (actionA.x[k] == 0) {
          actionA.score += 1;
        }
      }
      // 操作 B
      State actionB = beam[i-1][j];
      actionB.last = 'B';
      actionB.from = j;
      actionB.x[p[i]] -= 1;
      actionB.x[q[i]] -= 1;
      actionB.x[r[i]] -= 1;
      for(int k = 1; k <= N; ++k) {
        if (actionB.x[k] == 0) {
          actionB.score += 1;
        }
      }
      c.push_back(actionA);
      c.push_back(actionB);
    }
    // ソートして、良いのを選別する
    sort(c.begin(), c.end(), cmp);
    cntState[i] = min(width, (int) c.size());
    for(int j = 0; j < cntState[i]; ++j) {
      beam[i][j] = c[j];
    }
  }
}


// ==============================
// メイン
// ==============================

int main() {

	// true:ビジュアライザ用 false:提出用
	// isLocal = true;
	isLocal = false;

  // 初期設定
  init();

  // 実行
  beamSearch();

  // 復元
  int current = 0;
  for(int i = T; 0 < i; --i) {
    ans[i] = beam[i][current].last;
    current = beam[i][current].from;
  }

  // 出力
  for(int i = 1; i <= T; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}
