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
const int INF = 1001001001;

// 0-1 BFS を実装する関数
void zeroOneBFS(int start, const vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INF);  // 全頂点の初期距離を INF（非常に大きい値）に設定
    deque<int> dq;

    // 開始頂点の距離は 0 に設定して deque に追加
    dist[start] = 0;
    dq.push_back(start);

    // deque が空になるまで探索を続ける
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        // 頂点 u から出る全ての隣接頂点 v を見る
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            // u 経由で頂点 v へ到達する場合の距離が既知の距離より小さければ更新
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                // 辺の重みが 0 なら deque の前方に追加、1 なら後方に追加する
                if (w == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }
}

int main() {
    int n, m;
    // 頂点数 n と辺数 m を入力
    cin >> n >> m;

    // グラフの隣接リストを作成（pair: first が隣接頂点, second が辺の重み）
    vector<vector<pair<int, int>>> graph(n);

    // 各辺の情報 (u, v, w) を入力（u から v へ、w は 0 または 1）
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // 有向グラフの場合はここで OK。
        // 無向グラフの場合は以下の行も追加する:
        // graph[v].push_back({u, w});
    }

    int start;
    // 探索開始頂点を入力
    cin >> start;

    vector<int> dist;
    // 0-1 BFS を呼び出し、各頂点までの最短距離を求める
    zeroOneBFS(start, graph, dist);

    // 各頂点への距離を出力
    for (int i = 0; i < n; ++i) {
        cout << "頂点 " << start << " から 頂点 " << i << " までの最短距離: ";
        if (dist[i] == INF)
            cout << "到達不能" << "\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
