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

// 【鉄則本 A46】
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_at

// ==============================
// 変数
// ==============================

// true:ビジュアライザ用 false:提出用
bool isLocal;

// 入力データ
vector<string> inputs;

// inputファイル名
string inputFileName = "";

// 都市の数
int N;

// 都市の座標
vector<int> X;
vector<int> Y;

// 結果
vector<int> res;

// 訪問済みか否か
vector<bool> visited;

// スコア（最高点）
double maxScore = 0.0;

// 答え
vector<int> ans;



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
    N = stoi(s[0]);
  } else {
    cin >> N;
  }

  X.resize(N);
  Y.resize(N);
  visited.resize(N);

  if (isLocal) {
    rep(i, N) {
      vector<string> s = stringSplit(inputs[i+1], ' ');
      X[i] = stoi(s[0]);
      Y[i] = stoi(s[1]);
    }
  } else {
    rep(i, N) {
      cin >> X[i] >> Y[i];
    }
  }
}

// 実行
void run() {
  int current = 0;
  res.push_back(current);
  visited[current] = true;

  rep(i, N - 1) {
    double minDist = 100000.0;
    int minId = -1;
    rep(j, N) {
      if (visited[j]) { continue; }
      double dist = calc_dist({X[current], Y[current]}, {X[j], Y[j]});
      if (dist < minDist) {
        minDist = dist;
        minId = j;
      }
    }
    visited[minId] = true;
    res.push_back(minId);
    current = minId;
  }

  res.push_back(0);
}

// スコアを計算する
double calc_score() {
  double score = 0.0;
  int s = res.size();
  for(int i = 0; i < s - 1; ++i) {
    score += calc_dist({X[res[i]], Y[res[i]]}, {X[res[i+1]], Y[res[i+1]]});
  }
  return score;
}

// 0以上1未満のランダムな数を返す
double random_double() {
  return 1.0 * rand() / RAND_MAX;
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
  run();

  // スコアを計算
  maxScore = calc_score();

  // 試行回数
  int cnt = 0;
  while (cnt < 1900000) {
    // ランダムに入れ替える
    int l = generateRandom(1, N - 1);
    int r = generateRandom(1, N - 1);
    if (r < l) {
      swap(l, r);
    }
    reverse(res.begin() + l, res.begin() + r + 1);
    double newScore = calc_score();

    // 焼きなまし法
    double T = 30.00 - 28.00 * (cnt + 1) / 1900000.0;
    double P = exp(min(0.0, (maxScore - newScore) / T));
    double R = random_double();
    if (R <= P) {
      maxScore = newScore;
    } else {
      reverse(res.begin() + l, res.begin() + r + 1);
    }
    cnt++;
  }
;
  // 答えを出力
  for(auto i: res) {
    cout << i + 1 << endl;
  }
  return 0;
}
