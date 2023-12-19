/**
 * @brief 根付き木
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX     100005
#define NIL     -1

typedef struct {
    int parent;     // 親ノード
    int left;       // 左の子ノード
    int right;      // 右の子ノード
} Node;

Node Tree[MAX];
int n, Depth[MAX];

/**
 * @brief 出力
 * @param [in] u ノード番号
*/
static void print(int u)
{
    cout << "node " << u << ": ";
    cout << "parent = " << Tree[u].parent << ", ";
    cout << "depth = " << Depth[u] << ", ";

    if (Tree[u].parent == NIL) {
        cout << "root, ";
    } else if (Tree[u].left == NIL) {
        cout << "leaf, ";
    } else {
        cout << "internal node, ";
    }

    cout << "[";

    int c;
    for (int i = 0, c = Tree[u].left; c != NIL; i++, c = Tree[c].right) {
        if (i) {
            cout << ", ";
        }
        cout << c;
    }
    cout << "]" << endl;
}

/**
 * @brief 再帰的に深さを求める
 * @param [in] u ノード番号
 * @param [in] p 深さ
*/
static void recursive(int u, int p)
{
    Depth[u] = p;
    if (Tree[u].right != NIL) {
        recursive(Tree[u].right, p);    // 右の兄弟に同じ深さを設定
    }
    if (Tree[u].left != NIL) {
        recursive(Tree[u].left, p + 1); // 最も左の子に自分の深さ+1を設定
    }
}

int main()
{
    int id;         // 節点番号
    int k;          // 次数
    int c;          // 子の節点番号
    int leaf;       // 葉
    int root;       // 親
    cin >> n;
    for (int i = 0; i < n; i++) {
        Tree[i].parent = Tree[i].left = Tree[i].right = NIL;
    }

    for (int i = 0; i < n; i++) {
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            cin >> c;
            if (j == 0) {
                Tree[id].left = c;
            } else {
                Tree[leaf].right = c;
            }
            leaf = c;
            Tree[c].parent = id;
        }
    }

    for (int i = 0; i < n; i++) {
        if (Tree[i].parent == NIL) {
            root = i;
        }
    }

    recursive(root, 0);

    for (int i = 0; i < n; i++) {
        print(i);
    }

    return 0;
}