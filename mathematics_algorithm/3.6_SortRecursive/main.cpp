#include <bits/stdc++.h>
using namespace std;

int A[200009];
int C[200009];

/// @brief 選択ソート O(N^2)
/// @param n 数列の長さ
static void selection_sort(int n)
{
    for (int i = 0; i < n; i++) {
        int min = i;
        int min_val = A[i];
        for (int j = i + 1; j < n; j++) {
            if (A[j] < min_val) {
                min = j;
                min_val = A[min];
            }
        }
        swap(A[i], A[min]);
    }
}

/// @brief 階乗の計算(再帰関数)
/// @param n 数字
/// @return 数字
static int calc_factorial(int n)
{
    if (n == 1) {
        return n;
    }

    return n * calc_factorial(n - 1);
}

/// @brief ユークリッドの互除法(再帰関数)
/// @param a 割られる数
/// @param b 割る数
/// @return 余り
static long long gcd(long long a, long long b)
{
    // ベースケース
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

/// @brief マージソート
/// @param l 一番左のインデックス番号
/// @param r 一番右のインデックス番号
static void merge_sort(int l ,int r)
{
    // r-l=1は既にソート済
    if (r - l == 1) return;

    // 要素を2つに分けたあと、小さい配列をソート
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m, r);

    /* 
        この時点で以下の2つの配列がソートされている
        列A'に相当するもの [A[l], A[l+1], ... , A[m-1]]
        列B'に相当するもの [A[m], A[m+1], ... , A[r-1]]
        以下がマージ操作となる
    */

    int c1 = l, c2 = m, cnt = 0;
    while (c1 != m || c2 != r) {
        if (c1 == m) {
            // 列A'が空の場合
            C[cnt] = A[c2];
            c2++;
        } else if (c2 == r) {
            // 列B'が空の場合
            C[cnt] = A[c1];
            c1++;
        } else {
            if (A[c1] <= A[c2]) {
                C[cnt] = A[c1];
                c1++;
            } else {
                C[cnt] = A[c2];
                c2++;
            }
        }
        cnt++;
    }
    
    //
    for (int i = 0; i < cnt; i++) A[l +i] = C[i];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // selection_sort(n);
    // for (int i = 0; i < n; i++) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    // cout << calc_factorial(n) << endl;

    merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << A[i] << endl;

    return 0;
}