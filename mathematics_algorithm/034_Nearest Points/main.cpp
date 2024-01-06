/**
 * @brief 最近点対問題
 * @details 2次元平面上にN個の点があり、i番目の点(1≤i≤N)の座標は(xi ,yi)です。
最も近い2つの点の距離を求めてください。
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    double x[N], y[N];
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    double ans = 1000000000.0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            double x_dist = x[i] - x[j];
            double y_dist = y[i] - y[j];
            double distance = sqrt(x_dist * x_dist + y_dist * y_dist);
            ans = min(ans, distance);
        }
    }

    printf("%.12lf\n", ans);

    return 0;
}