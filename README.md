# cp-libraries

AtCoder等の競技プログラミングで使うためのスニペット、ライブラリや実装例（C++17）。

&nbsp;

## テンプレート

- [ACLを使う場合](./templates/main_acl.cpp)
- [ACLを使わない場合](./templates/main.cpp)

&nbsp;

## 入出力

### 入力を受け取る

- [標準入力から値を受け取る](./in_out/cin.cpp)
- [1行をまるごと受け取る](./in_out/getline.cpp)

### 出力する

- [値を出力する](./in_out/cout.cpp)
- [小数点を含む数値を出力する](./in_out/printf.cpp)

&nbsp;

## 文字列

- [ある文字を別の文字にすべて置き換える](./string/replace_all.cpp)
- [ある文字だけである長さの文字列を作る](./string/create_string.cpp)
- [大文字を小文字に変える](./string/to_lowercase.cpp)
- [小文字を大文字に変える](./string/to_uppercase.cpp)
- [ASCIIコードを取得する](./string/get_aßscii.cpp)
- [文字列の長さを揃える](./string/resize_string_length.cpp)
- [文字列の最後の文字を文字列の先頭へ移動させる](./string/insert_back_string.cpp)
- [文字列から特定の長さの文字列を抜き出す](./string/substr.cpp)
- [文字列から最後の文字を削除する](./string/delete_last_char.cpp)
- [文字の検索](./string/search_string.cpp)
- [文字列をある文字で区切る](./string/split_string.cpp)
- [文字列から空白を削除する](./string/remove_space.cpp)
- [文字列をハッシュで考える](./string/hash.cpp)
- [文字列が回文か否かを返す](./string/is_palindrome.cpp)
- [start <= end までの回文数（10進法, string）を作る](./string/createPalindromicNumbers.cpp)
- [小さい方から N 番目の回文数を作る](./string/create_palindrome.cpp)
- [s と t で先頭から見て何文字目まで一致するかを返す](./string/count_matching_prefix.cpp)
- [s と t で後ろから見て何文字目まで一致するかを返す](./string/count_matching_suffix.cpp)
- [文字列Sと文字列Tが部分列として先頭から何文字含まれているかを返す](./string/count_common_prefix_subsequence.cpp)
- [文字列Sと文字列Tが部分列として後ろから何文字含まれているかを返す](./string/count_common_suffix_subsequence.cpp)
- [i 文字目以降で最初に文字 c が登場する index を管理する配列を返す](./string/calc_next.cpp)
- [連長圧縮する（aaaabbbc -> a 4 b 3 c 1）](./string/length_encode.cpp)

&nbsp;

## 配列

- [配列を回転させる](./array/rotate.cpp)
- [余計な「.」を取り除く](./array/shape_up.cpp)
- [座標圧縮](./array/coordinate_compression.cpp)
- [連長圧縮する（{a,a,a,a,b,b,b,c} -> a 4 b 3 c 1）](./array/length_encode_array.cpp)
- [配列のある箇所から8方向チェックする例](./array/check_vector.cpp)

&nbsp;

## 円環

- [2点間の距離を測る](./circular_ring/calc_dist.cpp)
- [円環で壁がある場合の最短距離を測る](./circular_ring/calc_dist_with_wall.cpp)

&nbsp;

## 変換

- [文字列を数値に変換する](./convert/stoi.cpp)
- [数値を文字に変換する](./convert/get_char.cpp)
- [char を string に変換する](./convert/char_to_string.cpp)
- [変数を使って char に出力する](./convert/char_output.cpp)

&nbsp;

## ビット演算

- [ビット演算](./bit/bit_operation.cpp)

&nbsp;

## 日付・時間

- [うるう年判定](./datetime/is_leap_year.cpp)
- [yyyy 年 mm 年 dd 日 から d 日後の日付を配列で返す](./datetime/advance_date.cpp)

&nbsp;

## 並べ替え

- [バブルソート](./sort/bubblesort.cpp)
- [比較関数を使った並び替え](./sort/comparison_function.cpp)
- [比較関数（ラムダ式）を使った並び替え](./sort/comparison_function_lambda.cpp)

&nbsp;

## 再帰関数

- [全パターン列挙 - N人をグループに分ける](./recursion/enumerate_all_groupings.cpp)
- [全パターン列挙 - N人をT個のグループに分ける](./recursion/enumerate_groupings.cpp)
- [全パターン列挙 - N人でペアを作る](./recursion/create_pairs.cpp)

&nbsp;

## 探索

### 全探索

- [bit全探索](./search/bit_search.cpp)
- [bit全探索の0,1,2,..N版](./search/extended_bit_search.cpp)
- [順列全探索（数値）](./search/next_permutation_num.cpp)
- [順列全探索（文字列）](./search/next_permutation_str.cpp)

### 二分探索

- [二分探索（自作）](./search/binary_search.cpp)
- [二分探索（自作, ラムダ式でチェックする）](./search/binary_search_lambda.cpp)
- [二分探索（lower_bound）](./search/lower_bound.cpp)
- [二分探索（upper_bound）](./search/upper_bound.cpp)

### しゃくとり法

- [しゃくとり法](./search/shakutori.cpp)

&nbsp;

## 累積和・いもす法

- [累積和](./prefix_sum/prefix_sum.cpp)
- [2次元累積和](./prefix_sum/prefix_sum_2d.cpp)
- [いもす法](./prefix_sum/imos.cpp)
- [2次元いもす法](./prefix_sum/imos_2d.cpp)

&nbsp;

## データ構造

### STL

- [vector](./data_structure/vector.cpp)
- [set](./data_structure/set.cpp)
- [map](./data_structure/map.cpp)
- [multiset](./data_structure/multiset.cpp)
- [stack](./data_structure/stack.cpp)
- [queue](./data_structure/queue.cpp)
- [deque](./data_structure/deque.cpp)
- [priority_queue](./data_structure/priority_queue.cpp)
- [tuple](./data_structure/tuple.cpp)

### Union-Find

- [Union-Find（基本）](./data_structure/unionfind.cpp)
- [Union-Find（ACL）](./data_structure/unionfind_acl.cpp)

### Binary Indexed Tree (BIT, Fenwick Tree)

- [Fenwick Tree（ACL）](./data_structure/bit_acl.cpp)
- [Fenwick Tree で転倒数を数える（ACL）](./data_structure/count_inversion_number.cpp)
- [Fenwick Tree インデックス以下の最大値を取得する例](./data_structure/bit_max.cpp)

### ダブリング

- [ダブリング](./data_structure/doubling.cpp)

### セグメントツリー

- [区間の最大値を求める(一点更新・区間最大値)](./data_structure/rmq.cpp)
- [区間の合計を求める(一点更新・区間合計)](./data_structure/rsq.cpp)

&nbsp;

## グラフ

### BFS, DFS

- [BFS（基本）](./graph/bfs.cpp)
- [BFS（グリッド）](./graph/bts_grid.cpp)
- [01 BFS](./graph/bfs_01.cpp)
- [DFS（基本）](./graph/dfs.cpp)
- [DFS（ラムダ式で書いた例）](./graph/dfs_lambda.cpp)
- [DFS（連結成分の大きさを数える）](./graph/dfs_size.cpp)
- [DFS（オイラーツアー）](./graph/dfs_euler_tour.cpp)
- [DFS (連結成分ごとの頂点数と辺の数を数える)](./graph/dfs_count_vertices_and_edges.cpp)

### 閉路検知

- [閉路検知（Union-Find）](./graph/cycle_detection_dsu.cpp)
- [閉路検知（DFS）](./graph/cycle_detection_dfs.cpp)

### 最短経路

- [ダイクストラ法](./graph/dijkstra.cpp)
- [ワーシャルフロイド法](./graph/floyd_warshall.cpp)
- [ベルマンフォード法](./graph/bellman_ford.cpp)
- [負閉路を探す](./graph/search_negative_cycle.cpp)

### 二部グラフ

- [二部グラフの判定](./graph/bipartite_graph.cpp)

### 二分探索木

- [二分探索木](./graph/binary_search_tree.cpp)

### 最小全域木

- [クラスカル法（ACL）](./graph/kruskal.cpp)
- [プリム法](./graph/prim.cpp)

### トポロジカルソート

- [トポロジカルソート](./graph/topoligical_sort.cpp)

### 最小共通祖先（LCA）

- [最小共通祖先（LCA）](./graph/lca.cpp)

### ネットワークフロー

- [最大フロー問題](./graph/max_flow.cpp)
- [最大フロー問題（ACL）](./graph/max_flow_acl.cpps)
- [最小費用流問題](./graph/min_cost_flow.cpp)
- [最小費用流問題（ACL)](./graph/min_cost_flow_acl.cpp)
- [二部マッチング問題](./graph/bipartite_matching.cpp)
- [二部マッチング問題（ACL）](./graph/bipartite_matching_acl.cpp)

&nbsp;

## 木

### 木DP

- [全方位木DP](./tree/rerooting.cpp)

&nbsp;

## 数学

### 約数, 倍数

- [約数列挙](./math/divisor.cpp)
- [最大公約数](./math/gcd.cpp)
- [最小公倍数](./math/lcm.cpp)
- [拡張ユークリッドの互除法](./math/expanted_euclid.cpp)

### 素数

- [素数判定](./math/is_prime.cpp)
- [素数列挙](./math/prime_factor.cpp)
- [素因数分解（簡易版）](./math/prime_factor_easy.cpp)
- [ミラー・ラビンの素数判定法](./math/miller_rabin_is_prime.cpp)
- [ポラード・ロー素因数分解法](./math/pollard.cpp)

### エラストテネスの篩

- [エラストテネスの篩](./math/eratosthenes_sieve.cpp)

### ◯ 進法

- [10進数を2進数に変換する](./math/binary.cpp)
- [N進数をK進数に変換する](./math/convert.cpp)

### mod

- [mod の値を指定して余りを計算する（mint)](./math/set_mod.cpp)
- [割り切れる区間を求める](./math/dividable_section.cpp)
- [現在の数の余りと新しい桁数から新しい余りを計算する](./math/calc_new_mod.cpp)

### 和

- [xの各桁の和を計算する](./math/calc_sum_digit.cpp)
- [(ax + b) \ m の合計を計算する（ACL）](./math/floor_sum.cpp)
- [0 から v までの XOR を計算する](./math/calc_xor.cpp)
- [a の 0 乗から a の b 乗までの合計 (mint) を計算する（ACL）](./math/calc_sum_of_nth_power.cpp)
- [ニム和（配列全て XOR した値）を求める](./math/nim_sum.cpp)

### 指数関数

- [ルートを計算する](./math/sqrt.cpp)
- [べき乗（累乗）を計算する](./math/pow.cpp)
- [べき乗（累乗）を計算する(自作関数)](./math/my_pow.cpp)
- [a の b 乗を mod で割ったあまりを計算する](./math/pow_mod.cpp)
- [m の n 乗を繰り返し二乗法で計算する](./math/pow_mod_2.cpp)
- [2 の n 乗 (mint) を計算する（ACL）](./math/calc_nth_power.cpp)
- [x の -n 乗（mint）を計算する（ACL）](./math/calc_minus_nth_power.cpp)

### 幾何

- [ラジアンを度に変換する](./math/radians_to_degrees.cpp)
- [点 p1 から原点の角度を求める](./math/calc_angle.cpp)
- [点 p1 と点 p2 の距離を計算する](./math/calc_dist.cpp)
- [点 p1 と点 p2 を使った正方形の座標（p3, p4）を返す](./math/calc_square_using_points.cpp)
- [2 本の線分が交わっているかをチェックする](./math/check_cross.cpp)
- [3 点から三角形の面積を計算する](./math/calc_triangle.cpp)
- [2 つの区間 [a,b]と[c,d] に共通する部分があるかをチェックする](./math/common_interval.cpp)
- [2 つの円の位置関係を調べる](./math/check_circles_pos.cpp)
- [円と四角の衝突判定](./math/check_circle_and_rectangle.cpp)
- [2点（p1, p2）を結ぶ直線の上に 点（p3）があるか否かをチェックする](./math/check_same_line.cpp)

### 組み合わせ

- [n_C_a を計算する](./math/calc_nCa.cpp)
- [n_C_a を計算する（ACL）](./math/calc_nCa_acl.cpp)
- [n_C_a を計算する（n が大きくて a が小さい場合. ACL）](./math/calc_nCa_large_n_acl.cpp)
- [n_C_a を逆算する](./math/back_calc_nCa.cpp)
- [n_P_k を計算する（ACL）](./math/calc_nPk.cpp)

### 数列

- [フィボナッチ数列（mint）](./math/fibonacci.cpp)
- [フィボナッチ数列（行列, mod）](./math/fibonacci_matrix.cpp)

### その他

- [N 以下の整数で、下から i 桁目が j となるような整数の個数を返す](./math/count_number.cpp)
- [逆ポーランド記法で表された計算式を計算する](./math/calc_poland.cpp)
- [逆ポーランド記法で表された計算式を通常の計算式に戻す](./math/decode_poland.cpp)
- [小町算](./math/komachizan.cpp)
- [虫食算](./math/mushikuizan.cpp)
- [数独を解く](./math/sudoku.cpp)
- [覆面算](./math/fukumenzan.cpp)

&nbsp;

## ゲーム

### トーナメント

- [2^N 人が参加するトーナメントで M 回戦目に当たる可能性のある人を列挙する](./game/tournament.cpp)

&nbsp;

## ヒューリスティック

### よく使うもの

- [指定した txt ファイルを読み込む](./heuristic/import_file.cpp)
- [txt ファイルに出力する](./heuristic/export_file.cpp)
- [start 以上、end 以下でランダムな int を返す](./heuristic/generate_ramdom.cpp)
- [0 から cnt - 1 までをランダムに並び替える](./heuristic/shuffle_numbers.cpp)
- [得点を管理する](./heuristic/score.cpp)
- [制限時間を設定して処理する](./heuristic/timer.cpp)


### 局所探索法

- [局所探索法の例](./heuristic/example_ramdom.cpp)

### 焼きなまし法

- [焼きなまし法の例](./heuristic/example_sa.cpp)
- [焼きなまし法の勉強](./heuristic/example_sa2.cpp)

### ビームサーチ

- [ビームサーチの例](./heuristic/example_beamsearch.cpp)
