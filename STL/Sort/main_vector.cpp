/**
 * @brief STLのsort関数
 * sort関数はクイックソートがベースとなっているため、
 * O(nlog(n))で動く高速なソートである。
 * O(n^2)となってしまう欠点も対策済み。
 * ただし、sortは安定ソートではないため注意が必要。
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> v;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // 昇順にソート
    // 第一引数に先頭イテレータ
    // 第荷引数に末尾イテレータ
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}