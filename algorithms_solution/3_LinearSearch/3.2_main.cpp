#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    // 線形探索
    bool exist = false;         // フラグ
    int found_id = -1;          // 添字に-1はありえないので設定
    for (int i; i < N; i++) {
        if (a[i] == v) {
            exist = true;
            found_id = i;
            break;
        }
    }

    if (exist) {
        cout << found_id << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}