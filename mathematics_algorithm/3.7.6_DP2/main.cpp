/**
 * @brief カエルの移動の一般化
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int H[10];      // 足場
    int dp[10];     // 最小の体力
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) dp[i] = 0;
        else if (i == 1) dp[i] = abs(H[i-1] - H [i]);
        else if (i >= 2) {
            // 1個前の足場からジャンプ
            int v1 = dp[i - 1] + abs(H[i - 1] - H[i]);
            // 2個前の足場からジャンプ
            int v2 = dp[i - 2] + abs(H[i - 2] - H [i]);
            dp[i] = min(v1, v2);
        }
    }

    cout << dp[N-1] << endl;

    return 0;
}