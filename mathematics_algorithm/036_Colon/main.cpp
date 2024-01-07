/**
 * @brief ABC168-C
 * @details 時針が1分間に進む角度は、1時間で30度なので
 * 30[度] / 60[分] = 0.5[度]
 * 分針が1分間に進む角度は、1時間で360度なので、
 * 360[度] / 60[分] = 6[度]
*/

#include <bits/stdc++.h>
using namespace std;

# define PI acos(-1)

int main()
{
    double A, B, H, M;
    cin >> A >> B >> H >> M;

    // H時M分の時針と分針の角度はそれぞれ
    // 時針: 30H + 0.5M度
    // 分針: 6M度
    double AngleH = 30.0 * H + 0.5 * M;
    double AngleM = 6.0 * M;

    // 時針と分針の先端座標を求める
    double Hx = A * cos(AngleH * M_PI / 180.0);
    double Hy = A * sin(AngleH * M_PI / 180.0);
    double Mx = B * cos(AngleM * M_PI / 180.0);
    double My = B * sin(AngleM * M_PI / 180.0);

    // 2点間の距離を求める
    double ans = sqrt((Hx - Mx) * (Hx - Mx) + (Hy - My) * (Hy - My));

    printf("%.12lf\n", ans);

    return 0;
}