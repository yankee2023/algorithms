#include <bits/stdc++.h>
using namespace std;

#define MAX     2000001
#define VMAX    10000

// 数列の数字の出現回数を数える
// インデックス番号が出現する数字
// 配列中身が出現回数
int Counter[VMAX + 1];

/**
 * @brief 計数ソート
 * @param [in] A 入力数列
 * @param [out] B 出力配列
 * @param [in] n 要素数
*/
static void counting_sort(int A[], int* B[], int n)
{
    for (int i = 0; i < VMAX; i++) {
        Counter[i] = 0;
    }

    // C[i]にiの出現数を記録
    for (int i = 0; i < n; i++) {
        Counter[A[i]]++;
    }

    // C[i]にi以下の数の出現数を記録(出現回数の累積和)
    for (int i = 1; i < VMAX; i++) {
        Counter[i] = Counter[i] + Counter[i -1];
    }

    // 出力配列BにAの要素をコピー
    for (int i = 0; i < n; i++) {
        B[Counter[A[i]]] = &A[i];
        Counter[A[i]]--;
    }
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    int* B[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    counting_sort(A, B, n);

    for (int i = 1; i < n + 1; i++) {
        if (i > 1){
            cout << " ";
        }
        cout << *B[i];
    }
    cout << endl;

    return 0;
}