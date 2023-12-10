#include <bits/stdc++.h>
using namespace std;

/**
 * @brief パーティション
 * @param [in] A 配列
 * @param [in] p 配列の左端の添字
 * @param [in] r 配列の右端の添字、基準値
 * @return 基準値
*/
static int partition(int A[], int p, int r) {
    int standard_val = A[r];
    for (int i = p; i < r; i++) {
        if (A[i] <= standard_val) {
            swap(A[p], A[i]);
            p++;
        }
    }
    swap(A[r], A[p]);
    return p;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int ans = partition(A, 0, N-1);

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        if (i == ans) cout << "[";
        cout << A[i];
        if (i == ans) cout << "]";        
    }
    cout << endl;

    return 0;
}