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
  データが昇順もしくは降順に整列されていることが前提。一回の比較演算を行うごとに探索範囲が半分になっていく性質より、計算量はO(logn)となる。  
- [ハッシュ(Hash)](ALDS1_4_C_Dictionary/main.c)  
  衝突回避の方法としてダブルハッシュを用いたオープンアドレス法で実装。検索、削除にはO(n)の計算量がかかる。

# 再帰・分割統治法
- [全探索(Exhaustive Search)](ALDS1_5_A_Exhaustive-Search/main.cpp)

# メモ
- ラウンドロビンスケジューリング  
- クオンタム  
- 番兵法  
  要素の列の終端にデータを加えることで、ループの終了条件の判定回数を減らすことができる。  
- ループ終了判定  
  - 列の末尾に到達したか  
  - 列のお湯祖が探している値が一致したか  
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