#include <bits/stdc++.h>
using namespace std;

#define MAX         1000000
#define SENTINEL    2000000000

typedef struct
{
    char    suit;   // 記号
    int     value;  // 数字
} Card;

Card L[(MAX / 2) + 2], R[(MAX / 2) + 2];

static void merge(Card A[], int n, int left, int mid, int right)
{
    int i, j;
    int n1 = mid - left;
    int n2 = right - mid;
    for (i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }

    L[n1].value = R[n2].value = SENTINEL;
    i = j = 0;

    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
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
*/
static void merge_sort(Card A[], int n, int left, int right)
{
    int mid;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        merge_sort(A, n, left, mid);
        merge_sort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

/**
 * @brief パーティション
*/
static int partition(Card A[], int n, int left, int right)
{
    Card tmp, x;
    x = A[right];
    int i = left - 1;
    for (int j = 0; j < right; j++) {
        if (A[j].value <= x.value) {
            i++;
            // tmp = A[i];
            // A[i] = A[j];
            // A[j] = tmp;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[right]);
    return i + 1;
}

/**
 * @brief クイックソート
*/
static void quick_sort(Card A[], int n, int left, int right)
{
    int q;
    if (left < right) {
        q = partition(A, n, left, right);
        quick_sort(A, n, left, right - 1);
        quick_sort(A, n, left + 1, right);
    }
}

int main()
{
    int n, v;
    Card merge[MAX], quick[MAX];
    char S[10];
    int stable = 1;     // 1:安定 , 0:不安定

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> S >> v;
        merge[i].suit = quick[i].suit = S[0];
        merge[i].suit = quick[i].value = v;
    }

    merge_sort(merge, n, 0, n);
    quick_sort(quick, n, 0, n -1);

    for (int i = 0; i < n; i++) {
        if (merge[i].suit != quick[i].suit) {
            stable = 0;
        }
    }

    // マージソートとクイックソートの比較
    if (stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << quick[i].suit << quick[i].value << endl;
    }

    return 0;
}