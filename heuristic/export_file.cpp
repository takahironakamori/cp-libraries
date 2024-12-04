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

// txtファイルに出力する
void output_file(string s) {
  ofstream outputfile("output.txt", ios::app);
	outputfile << s << "\n";
  outputfile << flush;
  outputfile.close();
}

int main() {

  // 同じディレクトリに output.txt を出力する。
  // output.txt には test が書いてある。
  output_file("test");

  return 0;
}
view raw
