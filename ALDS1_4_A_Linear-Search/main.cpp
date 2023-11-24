#include <iostream>
#include <list>
#include <algorithm>
#include <stdio.h>
using namespace std;

static int linearSearch(int S[], int n, int key) {
    int i = 0;
    S[n] = key;
    while (S[i] != key) {
        i++;
    }
    return i != n;
}

int main() {
    int n, q, key, sum = 0, S[10000+1];
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    
    cin >> q;
    for (int i = 0; i < q; i++) {
        scanf("%d", &key);
        if (linearSearch(S, n, key)) {
            sum++;
        }
    }

    printf("%d\n", sum);

    return 0;
}