#include <iostream>
#include <algorithm>
using namespace std;
static const int INT_MAX = 200000;

int main() {
    int n, R[INT_MAX];
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    
    int max_val = -2000000000;   // 十分小さい値で初期化
    int min_val = R[0];

    for (int i = 1; i < n; i++) {
        max_val = max(max_val, R[i] - min_val);
        min_val = min(min_val, R[i]);
    }

    cout << max_val << endl;
    
    return 0;
}