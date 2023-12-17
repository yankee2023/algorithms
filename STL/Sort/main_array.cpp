#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // 昇順にソート
    // 第一引数に先頭ポインタ
    // 第荷引数に末尾ポインタ
    sort(array, array + n);

    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    

    return 0;
}
