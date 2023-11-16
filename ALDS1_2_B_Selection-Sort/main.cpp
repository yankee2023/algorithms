#include <iostream>
using namespace std;

/**
 * @brief 選択ソート
*/
void selection_sort(int A[], int N) {
    int cnt = 0, minj = 0;
    
    for (int i = 0; i < N; i++) {
        minj = i;    
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        
        if (i != minj) {
            swap(A[i], A[minj]);
            cnt++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (0 == i) {
            cout << A[i];
            continue;
        }
        cout << " " << A[i];
    }
    cout << endl << cnt << endl;
}

int main() {
    int N, A[110] {};
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    selection_sort(A, N);
    
    return 0;
}