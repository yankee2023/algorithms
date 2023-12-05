#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x;
    double y;
};

/**
 * @brief 度からラジアンへ単位変換
 * 正三角形ということが既知なので60度をπ/3へ変換
 * @return ラジアン単位系
*/
static double degree_to_radian() {
    return M_PI * 60.0 / 180.0;
}

/**
 * @brief コッホ曲線の頂点を計算
 * @param [in] n 繰り返し回数
 * @param [in] a 始点座標
 * @param [in] b 終点座標
*/
static void koch(int n, Point a, Point b) {
    if (n == 0) {
        return;
    }

    Point s, t;     // 3等分したときの座標
    Point u;        // 正三角形の頂点座標
    double rad = degree_to_radian();
    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = (t.x - s.x) * cos(rad) - (t.y - s.y) * sin(rad) + s.x;
    u.y = (t.x - s.x) * sin(rad) + (t.y - s.y) * cos(rad) + s.y;

    // 1回の試行で4辺できる
    koch(n - 1, a, s);
    cout << s.x << " " << s.y << endl;
    koch(n - 1, s, u);
    cout << u.x << " " << u.y << endl;
    koch(n - 1, u, t);
    cout << t.x << " " << t.y << endl;
    koch(n - 1, t, b);
}

int main() {
    int n;
    cin >> n;
    Point a = {0, 0};
    Point b = {100, 0};

    // 小数点表記フォーマット
    cout << fixed;
    cout << setprecision(8) << a.x << " " << a.y << endl;
    koch(n, a, b);
    cout << b.x<< " "  << b.y << endl;

    return 0;
}