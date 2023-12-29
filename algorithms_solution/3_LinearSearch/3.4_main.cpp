/**
 * @note ペア和のK以上の中での最小値
*/

#include <bits/stdc++.h>
using namespace std;

const int INF   = 20000000; //十分大きな値

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    // 線形探索
    int min_value = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 和がK未満の場合は捨てる
            if (a[i] + b[i] < K) continue;

            // 最小値更新
            if (a[i] + b[i] < min_value) {
                min_value = a[i] + b[i];
            }
        }
    }

    cout << min_value << endl;

    return 0;
}