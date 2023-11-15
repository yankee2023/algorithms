#include <iostream>
#include <vector>
#define INT32_MIN (-2147483647-1)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> R(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    
    int ans = INT32_MIN;
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            int max_tmp = R[j] - R[i];
            if (ans < max_tmp){
                ans = max_tmp;
            }
        }
    }
    cout << ans << endl;
    return 0;
}