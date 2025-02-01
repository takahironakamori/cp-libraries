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


// start 以上、end 以下でランダムなintを返す
random_device rd;
default_random_engine eng(rd());
int generateRandom(int start, int end) {
  uniform_real_distribution<double> distr(start - 1, end);
  return ceil(distr(eng));
}


// 0 から cnt - 1 までをランダムに並び替える
mt19937 gen(rd());
vector<int> shuffleNumbers(int cnt) {
  vector<int> v(cnt);
  rep(i, cnt) {
    v[i] = i;
  }
  shuffle(v.begin(), v.end(), gen);
  return v;
}


class Score{
  private:
    // 今の最高点
    int best_score_;
  
    // 今の最高点の内訳
    vector<int> best_score_details_;
    
    // 内訳の数
    int best_score_size_;

    // 今の得点
    int current_score_;

    // 今の得点の内訳
    vector<int> current_score_details_;

    // 更新候補の最高点
    int temp_score_;

    // 更新候補のターゲットとその得点
    vector<P> temp_score_details_;

  public:
    // Constructor
    Score(const int n) {
      best_score_size_ = n;
      best_score_details_.resize(n);
      current_score_details_.resize(n);
      best_score_ = 0;
      current_score_ = 0;
    }

    // 今の得点を全て更新する
    void updateCurrentScore(const vector<int>& v) {
      int n_ = v.size();
      current_score_ = 0;
      rep(i, n_) {
        current_score_details_[i] = v[i];
        current_score_ += v[i];
      }
    }

    // 今の得点が最高点より高い場合は、最高点を更新する
    void updateBestScoreIfCurrentHigher() {
      if(best_score_ < current_score_) {
        cout << "Updated Best Score" << endl;
        best_score_ = current_score_;
        best_score_details_ = current_score_details_;
      } else {
        cout << "Not Best Score" << endl;
      }
    }

    // 指定するターゲットを得点を更新して、得点を仮計算する
    void excludeFromBestScore(const vector<P>& targets) {
      temp_score_ = best_score_;
      temp_score_details_ = targets;
      int n_ = targets.size();
      rep(i, n_) {
        int target_ = targets[i].first;
        int new_score_ = targets[i].second;
        int prev_score_ = best_score_details_[target_];
        temp_score_ -= prev_score_;
        temp_score_ += new_score_;
      }
    }

    // 仮計算した得点が最高点より高い場合は、最高点を更新する
    void updateBestScoreIfTempHigher() {
      if(best_score_ < temp_score_) {
        cout << "Updated Best Score" << endl;
        best_score_ = temp_score_;

        // 内訳を更新する
        int n_ = temp_score_details_.size();
        rep(i, n_) {
          int target_ = temp_score_details_[i].first;
          int new_score_ = temp_score_details_[i].second;
          best_score_details_[target_] = new_score_;
        }
      } else {
        cout << "Not Best Score" << endl;
      }
    }

    // Debug : 最高得点を出力する
    void showBestScore() {
      cout << "Best Score : " << best_score_ << endl;
      int n_ = best_score_details_.size();
      rep(i, n_) {
        cout << i << " : " << best_score_details_[i] << " ";
      } 
      cout << endl;
    }
};


int main() {
  int N = 10;

  Score score{N};

  vector<int> scoreDetail(N);
  
  // ダミーで点数を入れる
  rep(i, N) {
    scoreDetail[i] = generateRandom(100, 999);
  }

  // 今の得点を全て更新する
  score.updateCurrentScore(scoreDetail);

  // 今の得点が最高点より高い場合は、最高点を更新する
  score.updateBestScoreIfCurrentHigher();

  // Debug : 最高得点を出力する
  score.showBestScore();

  // 除外するターゲットを選ぶ
  vector<int> v = shuffleNumbers(N);
  int cnt = generateRandom(0, N);
  vector<int> targets;
  rep(i, cnt) {
    targets.push_back(v[i]);
  }

  // ターゲットのスコアを再計算
  int n_ = targets.size();
  vector<P> new_score;
  rep(i, n_) {
    int score = generateRandom(100, 999);
    new_score.push_back(make_pair(targets[i], score));
  }
  // check
  cout << "new_score" << endl;
  rep(i, n_) {
    cout << new_score[i].first << " : " << new_score[i].second << " ";
  }
  cout << endl;

  // 指定するターゲットを最高点の状況から外す
  score.excludeFromBestScore(new_score);

  // 仮計算した得点が最高点より高い場合は、最高点を更新する
  score.updateBestScoreIfTempHigher();
  
  // Debug : 最高得点を出力する
  score.showBestScore();

  return 0;
}
