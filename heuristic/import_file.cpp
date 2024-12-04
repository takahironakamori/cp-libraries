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

// 指定したtxtファイルを読み込む
vector<string> import_file(string name) {
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

int main() {

  // 同じディレクトリにある 001.txt を読み込む。
  vector<string> res = import_file("001.txt");

  for(auto s:res) {
    cout << s << endl;
  }

  return 0;
}
