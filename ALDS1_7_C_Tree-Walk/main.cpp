#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
#define NIL -1

/// @brief ノード
typedef struct {
    int id;
    int left;
    int right;
} Node;

Node Tree[MAX];

/// @brief 先行順巡回
/// 根節点->左部分木->右部分木の順で節点番号を出力
/// @param u 根節点番号
static void pre_parse(int u)
{
    if (u == NIL) {
        return;
    }

    cout << " " << u;
    pre_parse(Tree[u].left);
    pre_parse(Tree[u].right);
}

/// @brief 中間順巡回
/// 左部分木->根節点->右部分木の順で節点番号を出力
/// @param u 根節点番号
static void in_parse(int u)
{
    if (u == NIL) {
        return;
    }

    in_parse(Tree[u].left);
    cout << " " << u;
    in_parse(Tree[u].right);
}

/// @brief 後行順巡回
/// 左部分木->右部分木->根節点の順で節点番号を出力
/// @param u 根節点番号
static void post_parse(int u)
{
    if (u == NIL) {
        return;
    }

    post_parse(Tree[u].left);
    post_parse(Tree[u].right);
    cout << " " << u;
}

int main()
{
    int n, v, l, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Tree[i].id = NIL;
    }

    for (int i = 0; i < n; i++) {
        cin >> v >> l >> r;
        Tree[v].left = l;
        Tree[v].right = r;
        if (l != NIL) {
            Tree[l].id = v;
        }
        if (r != NIL) {
            Tree[r].id = v;
        }
    }

    int root;
    for (int i = 0; i < n; i++) {
        if (Tree[i].id == NIL) {
            root = i;
        }
    }

    cout << "Preorder" << endl;
    pre_parse(root);
    cout << endl;

    cout << "Inorder" << endl;
    in_parse(root);
    cout << endl;

    cout << "Postorder" << endl;
    post_parse(root);
    cout << endl;

    return 0;
}