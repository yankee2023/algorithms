#include <iostream>
using namespace std;

/**
 * @brief バブルソート
*/
void bubble_sort(int A[], int N) {
    bool bubble_flag = true;
    int tmp = 0, cnt = 0;
    while (bubble_flag) {
        bubble_flag = false;
        for (int i = N-1; i > 0; i--) {
            if (A[i] < A[i-1]) {
                tmp = A[i-1];
                A[i-1] = A[i];
                A[i] = tmp;
                cnt++;
                bubble_flag = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (0 == i) {
            cout << A[i];
            continue;
        }
        cout << " " << A[i];
    }
    cout << endl <<  cnt << endl;    
}

int main() {
    int N, A[110];
    cin >> N;
    for (int  i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    bubble_sort(A, N);
    return 0;
}