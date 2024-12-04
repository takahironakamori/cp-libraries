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

// うるう年か否かを返す
bool isLeapYear(int yyyy) {
  if(yyyy % 4 == 0) {
    if(yyyy % 100 == 0) {
      if(yyyy % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
  } else {
    return false;
  }
  return false;
}

// yyyy 年 mm 年 dd 日 から d 日後の日付を配列で返す
vector<int> advanceDate(int yyyy, int mm, int dd, int d) {
  while(0 < d) {
    dd++;
    int limit = 31;
    if(mm == 2) {
      if(isLeapYear(yyyy) == true) {
        limit = 29;
      } else {
        limit = 28;
      }
    } else if(mm == 4 || mm == 6 || mm == 9 || mm == 11) {
      limit = 30;
    }
    if(limit < dd) {
      dd = 1;
      mm++;
    }
    if (12 < mm) {
      yyyy++;
      mm = 1;
    }
    d--;
  }
  vector<int> res = {yyyy, mm, dd};
  return res;
}

int main() {
  int yyyy = 2024;
  int mm = 2;
  int dd = 14;

  // 2024年2月14日から20日後の日付（初日は含まない）を取得
  vector<int> res = advanceDate(yyyy, mm, dd, 20);

  yyyy = res[0];
  mm = res[1];
  dd = res[2];

  cout << yyyy << "/" << mm << "/" << dd << endl; // 2024/3/5
  return 0;
}
