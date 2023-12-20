# algorithms_and_data_structures
書籍「プログラミングコンテスト攻略のためのアルゴリズムとデータ構造」の修行  

# 初等的配列  
- [挿入ソート(Insertion Sort)](ALDS1_1_A_Insertion-Sort/main.cpp)  
- [バブルソート(Bubble Sort)](ALDS1_2_A_Bubble-Sort/main.cpp)  
- [選択ソート(Selection Sort)](ALDS1_2_B_Selection-Sort/main.cpp)  
- [安定なソート(Stable Sort)](ALDS1_2_C_Stable-Sort/main.cpp)  
- [シェルソート(Shell Sort)](ALDS1_2_D_Shell-Sort/main.cpp)  

# データ構造  
- [スタック(Stack)](ALDS1_3_A_Stack/main.cpp)  
- [キュー(Queue)](ALDS1_3_B_Queue/main.cpp)  
- [双方向連結リスト(Doubly Linked List)](ALDS1_3_C_Doubly-Linked-List/main.cpp)  
- [応用: 面積計算](ALDS1_3_D_Areas-on-the-Cross-Section-Diagram/main.cpp)  

# STL(Standard Template Library)  
- [スタック(Stack)](STL/Stack/main.cpp)  
- [キュー(Queue)](STL/Queue//main.cpp)  
- [可変長配列(Vector)](STL/Vector/main.cpp)  
  要素数がnのvectorに対する特定の位置へのデータ挿入や削除はO(n)の計算量が必要になるので注意。  
- [リスト(List)](STL/List/main.cpp)  
  ListではVectorのように[]演算子で要素へアクセスできないので注意。  
  しかし、ListはVectorと異なり、要素の挿入と削除をO(1)で高速に行うことができる。

# 探索
- [線形探索(Linear Search)](ALDS1_4_A_Linear-Search/main.c)  
  配列の先頭から各要素が目的の値と等しいか順番に調べる。計算量はO(n)。  
- [二分探索(Binary Search)](ALDS1_4_B_Binary-Search/main.c)  
  データが昇順もしくは降順に整列されていることが前提。一回の比較演算を行うごとに探索範囲が半分になっていく性質より、計算量はO(log(n))となる。  
- [ハッシュ(Hash)](ALDS1_4_C_Dictionary/main.c)  
  衝突回避の方法としてダブルハッシュを用いたオープンアドレス法で実装。検索、削除にはO(n)の計算量がかかる。

# 再帰・分割統治法
- [全探索(Exhaustive Search)](ALDS1_5_A_Exhaustive-Search/main.cpp)
- [コッホ曲線(Koch Curve)](ALDS1_5_C_Koch-Curve/main.cpp)

# 高等的配列
- [マージソート(Merge Sort)](ALDS1_5_B_Merge-Sort/main.cpp)  
  一般的にn個のデータの場合、約log(n)個の階層になる。各階層ごとに行われる全てのmergeの計算量はO(n)となる。よってマージソートの計算量はO(nlog(n))。
  高速で安定なソートアルゴリズムだが、入力データを保持する配列以外に一時的なメモリ領域が必要になる。
- [パーティション(Partition)](ALDS1_6_B_Partition/main.cpp)  
  ある基準値に対して、それよりも小さな値と大きな値を左右それぞれに分ける。一般的に右端の値を基準値に設定する。  
- [クイックソート(Quick Sort)](ALDS1_6_C_Quick-Sort/main.cpp)  
  ソートアルゴリズムの中で最も高速なアルゴリズム。平均計算量はO(nlog(n))だが、データの並び順によってはO(n^2)となることもある。また、再帰が深くなりスタックオーバーフローの可能性もある。そのため基準をランダムに選ぶ、配列から適当な値を選びその中央値を選ぶ、のように基準の選び方を工夫する必要がある。  
- [計数ソート(Counting Sort)](ALDS1_6_A_Counting-Sort/main.cpp)  
  入力配列の要素を後ろから選ぶことで安定なソートにある。各要素が0以上k以下である要素数nの数列に対して線形時間(O(n + k))で動く安定なソートアルゴリズムである。バケツソート、バケットソートなどとも呼ばれる。

# 木
- [根付き木(Rooted Tree)](ALDS1_7_A_Rooted-Trees/main.cpp)
- [二分木(Binary Tree)](ALDS1_7_B_Binary-Tree/main.cpp)  
- [木の巡回(Tree Walk)](ALDS1_7_C_Tree-Walk/main.cpp)

# メモ
- ラウンドロビンスケジューリング  
- クオンタム  
- 番兵法  
  要素の列の終端にデータを加えることで、ループの終了条件の判定回数を減らすことができる。  
- 配列などの線形探索時のループ終了判定は以下の2つ  
  - 列の末尾に到達したか  
  - 列の要素が探している値が一致したか  
- ハッシュ法  
  ハッシュ関数と呼ばれるハッシュ値によって、要素の格納場所を決定する。ハッシュテーブルと呼ばれる表を用いるアルゴリズム。  
  要素のキーを引数とした関数を呼び出すだけでその位置を特定でき、データの種類によっては高速なデータ検索が可能。  
- イテレータ  
  STLのコンテナの要素に対して反復処理を行うためのオブジェクト。コンテナ内での要素の位置を指すもので、ポインタのように扱うことができる。  
- コンテナ  
  オブジェクトの集まりを表すデータ構造、クラスのこと。コンテナはイテレータを扱うための同じ名前のメンバ関数を提供する。  
  - begin(): コンテナの先頭を指すイテレータを返す  
  - end(): コンテナの末尾を指すイテレータを返す  
- 分割統治法  
  1. 与えられた問題を部分問題に「分割」する(Divide)  
  2. 部分問題を再帰的に解く(Solve)  
  3. 得られた部分問題の解を「統合」して元の問題を解く(Conquer)  
- 木構造  
  木構造とは節点(Node)と節点同士を結ぶ辺(Edge)で表されるデータ構造である。  
- 根付き木(Rooted Tree)  
  根と呼ばれる他と区別された1つの節点を持つ木のことである。  
  根付き木の節点には親子関係があり、子を持たない節点は外部節点(External Node)または葉(Leaf)と呼び、葉ではない節点を内部節点(Internal Node)と呼ぶ。  
  根から節点までの経路長を深さ(Depth)と呼び、節点から葉までの最大経路長を高さ(Height)と呼ぶ。  
- 二分木
  1つの根を持ち全ての節点についてその子の数が2以下である木のこと。
  二分木は再帰的に定義可能で、以下のいずれかの条件を満たす木である。
  - 節点を全く持たない
  - 共通要素を持たない次の3つの頂点集合から構成される
    - 根(Root)
    - 左部分木(Left Subtree)と呼ばれる二分木
    - 右部分木(Right Subtree)と呼ばれる二分木