/**
 * @brief 階段の上り方
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int dp[100];    // N段目まで上がる方法の数

    // DP法
    for (int i = 0; i <= N; i++) {
        if (i == 0) dp[i] = 1;
        else if (i == 1) dp[i] = 1;
        else dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N] << endl;
    return 0;
}