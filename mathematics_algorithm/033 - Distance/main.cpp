/**
 * @brief 点と線分を求めるプログラム
 * @details 点A, B, Cを入力とし、
 * 点Aと線分BC上の点の最短距離を求める
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int64_t ax, ay;
    int64_t bx, by;
    int64_t cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    // ベクトルBA, BC, CA, CBの各成分を計算
    int64_t BAx = ax - bx, BAy = ay - by;
    int64_t BCx = cx - bx, BCy = cy - by;
    int64_t CAx = ax - cx, CAy = ay - cy;
    int64_t CBx = bx - cx, CBy = by - cy;

    // パターン1
    // 角ABCが90度以上、ベクトルBA, BCの内積が負
    // パターン2
    // 角ABC, ACBがともに90度以下
    // パターン3
    // 角ACBが90以上、ベクトルCA, CBの内積が負
    int32_t pattern = 2;
    if (BAx * BCx + BAy * BCy < 0LL) pattern = 1;
    if (CAx * CBx + CAy * CBy < 0LL) pattern = 3;

    // 点と直線の距離を求める
    double ans = 0.0;
    if (pattern == 1) ans = sqrt(BAx * BAx + BAy * BAy);
    if (pattern == 3) ans = sqrt(CAx * CAx + CAy * CAy);
    if (pattern == 2) {
        double S = abs(BAx * CAy - BAy * CAx);
        double BClen = sqrt(BCx * BCx + BCy * BCy);
        ans = S / BClen;
    }

    printf("%.12lf\n", ans);

    return 0;
}