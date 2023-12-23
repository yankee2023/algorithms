#include <iostream>
using namespace std;

struct Card {
    char suit;
    char value;
};

/**
 * @brief 表示
*/
void print(Card C[], int N) {
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cout << C[i].suit << C[i].value;
            continue;
        }
        
        cout << " " << C[i].suit << C[i].value;
    }
    cout << endl;
}

/**
 * @brief バブルソート選択ソートの結果比較
*/
static bool isStable(struct Card C1[], struct Card C2[], int N) {
    for (int i = 0; i < N; i++) {
        if (C1[i].suit != C2[i].suit) {
            return false;
        }
    }
    return true;
}

/**
 * @brief バブルソート
*/
static void bubbleSort(Card C[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= i + 1; j--) {
            if (C[j].value < C[j-1].value) {
                swap(C[j], C[j-1]);
            }
        }
    }
}

/**
 * @brief 選択ソート
*/
static void slectionSort(Card C[], int N) {
    int minj = 0;
    for (int i = 0; i < N; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (C[j].value < C[minj].value) {
                minj = j;
            }
        }
        swap(C[i], C[minj]);
    }
}

int main() {
    int N;
    Card C1[100], C2[100];
    char ch;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C1[i].suit >> C1[i].value;
    }
    
    for (int i = 0; i < N; i++) {
        C2[i] = C1[i];
    }
    
    bubbleSort(C1, N);
    slectionSort(C2, N);

    // バブルソートは安定なソートなので常に"Stable"となる
    print(C1, N);
    cout << "Stable" << endl;
    print(C2, N);
    if (isStable(C1, C2, N)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    
    return 0;
}