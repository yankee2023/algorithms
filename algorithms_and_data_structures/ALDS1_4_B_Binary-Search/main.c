#include <stdio.h>

#define NOT_FOUND   0
#define FIND        1

int n, A[1000000];

/**
 * @brief 二分探索処理
 * @param [in] key 探したい数字
 * @return 0: NOT_FOUND , 1: FIND
*/
static int binarySearch(int key) {
    int left = 0, right = n;
    int mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (key == A[mid]) {
            return FIND;
        } else if (key < A[mid]) {
            right = mid;
        } else if (key > A[mid]) {
            left = mid + 1;
        }
    }
    return NOT_FOUND;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    int q, key, ans = 0;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &key);
        ans += binarySearch(key);
    }
    
    printf("%d\n", ans);

    return 0;
}