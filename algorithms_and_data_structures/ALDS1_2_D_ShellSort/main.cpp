#include <iostream>
#include <vector>
using namespace std;

long long cnt;
int A[10000000];
int n;
vector<int> G;

/**
 * @brief 間隔gを指定した挿入ソート
*/
static void insertionSort(int A[], int n, int g) {
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
}

/**
 * @brief シェルソート
 * 数列G = {1, 4, 13, 40, 121, 364, 1093, ...}を生成
*/
static void shellSort(int A[], int n) {
    for (int h = 1; ; ) {
        if (h > n) {
            break;
        }
        G.push_back(h);
        h = 3*h + 1;
    }

    for (int i = G.size() - 1; i >= 0; i--) {
        // 逆順にG[i] = g を指定
        insertionSort(A, n, G[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cnt = 0;

    shellSort(A, n);

    cout << G.size() << endl;
    for (int i = G.size() - 1; i >= 0; i--) {
        cout << G[i];
        if (i) {
            cout << " ";
        }
    }
    cout << endl;
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << endl;
    }

    return 0;    
}