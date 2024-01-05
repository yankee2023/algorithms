#include <bits/stdc++.h>
using namespace std;

int n, q;
int A[50];

/**
 * @brief 再帰関数
 * @details 入力値mから選んだ要素を引いていき、
 * 整数が作れるかどうか判断する
 * @param [in] i 
 * @param [in] m 入力値
 * @return 0: 作成不可能, 1: 作成可能
*/
int solve (int i, int m) {
    if (0 == m) {
        // 長さ0は何も選択しなければ作れるので無条件で作成可能
        return 1;
    }
    if (i >= n) {
        return 0;
    }

    /* a || b 
       aを評価して、0ならbを評価a=0ならa、そうでなければb */
    int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> q;
    int m;
    for (int i = 0; i < q; i++) {
        cin >> m;
        if (solve(0, m)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}