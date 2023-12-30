/**
 * @brief 1~Nまでの総和を計算する再帰関数
*/

#include <bits/stdc++.h>
using namespace std;

int func(int N) {
    if (N == 0) return 0;

    int result = N + func(N-1);
    cout << N << " までの和 = " << result << endl;

    return result;
}

int main() {
    func(5);
}