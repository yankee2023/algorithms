#include <bits/stdc++.h>
using namespace std;

int n, pos;
vector<int> pre_order, in_order, post_order;

/// @brief 二分木の復元処理
/// @param left 左節点
/// @param right 右節点
static void reconstruction(int left, int right)
{
    if (left >= right) {
        return;
    }

    int root = pre_order[pos];
    pos++;

    // Inorderにおける位置
    int m = distance(in_order.begin(), find(in_order.begin(), in_order.end(), root));
    reconstruction(left, m);        // 左部分木の復元
    reconstruction(m + 1, right);   // 右部分木の復元
    post_order.push_back(root);
}

static void solve()
{
    pos = 0;
    reconstruction(0, pre_order.size());
    for (int i = 0; i < n; i++) {
        if (i) {
            cout << " ";
        }
        cout << post_order[i];
    }
    cout << endl;
}

int main()
{
    int k;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> k;
        pre_order.push_back(k);
    }

    for (int i = 0; i < n; i++) {
        cin >> k;
        in_order.push_back(k);
    }

    solve();

    return 0;
}