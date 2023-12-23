#include <bits/stdc++.h>
using namespace  std;

#define MAX_LOAD    100000
#define LOAD_NUM    100000  // 荷物の個数
#define MAX_WIGHT   10000   // １個あたりの最大重量

int32_t n, k;
int64_t T[MAX_LOAD];

/**
 * @brief 何個積載可能かチェック
 * @param [in] P 最大積載量
 * @return 積載荷物の個数
*/
static int32_t check(int64_t P) {
    int32_t i = 0;
    for (int32_t j = 0; j < k; j++) {
        int64_t s = 0;
        while (s + T[i] <= P) {
            s += T[i];
            i++;
            if (i == n) {
                return n;
            }
        }
    }

    return i;    
}

static int64_t solve() {
    int64_t left = 0;
    int64_t rigth = LOAD_NUM * MAX_WIGHT;
    int64_t mid;
    
    while (rigth - left > 1) {
        mid = (rigth + left) / 2;
        int32_t v = check(mid);
        if (v >= n) {
            rigth = mid;
        } else {
            left = mid;
        }
    }
    
    return right;
}

int32_t main() {
    cin >> n >> k;
    for (int32_t i = 0; i < n; i++) {
        cin >> T[i];
    }

    int64_t ans = solve();

    cout << ans << endl;

    return 0;
}