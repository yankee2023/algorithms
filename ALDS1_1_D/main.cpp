#include <iostream>
#include <vector>
#include <algorithm>
#define INT32_MIN (-2147483647-1)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> R(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    
    int min_val = R[0];
    int max_val = INT32_MIN;
    for (int i = i; i < n; i++) {
        max_val = max(max_val, R[i] - min_val);
        min_val = min(min_val, R[i]);
    }
    cout << max_val << endl;
    return 0;
}