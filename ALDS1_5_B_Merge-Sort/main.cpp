/**
 * @note n個の整数を含む数列Sを疑似コードに従ったマージソートで
 * 昇順に整列するプログラムを作成してください。
 * また、mergeにおける比較回数の総数を報告してください。
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX         500000
#define SENTINEL    2000000000

int L[MAX/2 + 2], R[MAX/2 + 2];
int cnt;

/**
 * @brief マージ
 * @param [in] A 数列
 * @param [in] n 試行回数
 * @param [in] left 左の要素
 * @param [in] mid 真ん中の要素
 * @param [in] right 右の要素
*/
static void merge(int A[], int n, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }

    L[n1] = R[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

/**
 * @brief マージソート
 * @param [in] A 数列
 * @param [in] n 試行回数
 * @param [in] left 左の要素
 * @param [in] right 右の要素
*/
static void merge_sort(int A[], int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2; 
        merge_sort(A, n, left, mid);
        merge_sort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main() {
    cnt = 0;
    int n, S[MAX];
    cin >> n;
    for (int i; i < n; i++) {
        cin >> S[i];
    }

    merge_sort(S, n, 0, n);

    for (int i = 0; i < n; i++) {
        if (i) {
            cout << " ";
        }
        cout << S[i];
    }
    cout << endl;
    cout << cnt << endl;
    
    return 0;
}