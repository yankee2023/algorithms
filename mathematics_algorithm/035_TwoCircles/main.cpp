/**
 * @brief 2つの円の関係
 * @details [1]一方の円が他方の円を完全に含み、2つの円は接していない
[2]一方の円が他方の円を完全に含み、2つの円は接している
[3]2つの円が互いに交差する
[4]2つの円の内部に共通部分は存在しないが、2つの円は接している
[5]2つの円の内部に共通部分は存在せず、2つの円は接していない
*/

#include <bits/stdc++.h>
using namespace std;

/// @brief 2つの円の関係を出力
/// @param r1 円1の半径
/// @param r2 円2の半径
/// @param origin_dist 2つの円の中心座標間の距離
static void print_circle(double r1, double r2, double origin_dist)
{
    if (origin_dist < abs(r1 - r2)) cout << "1" << endl;
    else if (origin_dist == abs(r1 - r2)) cout << "2" << endl;
    else if (origin_dist < r1 + r2) cout << "3" << endl;
    else if (origin_dist == (r1 + r2)) cout << "4" << endl;
    else cout << "5" << endl;
}

int main()
{
    double x1, y1, r1;
    double x2, y2, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;

    double origin_dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    print_circle(r1, r2, origin_dist);

    return 0;
}