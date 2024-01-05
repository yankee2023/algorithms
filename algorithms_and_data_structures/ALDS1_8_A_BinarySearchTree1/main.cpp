/**
 * @note 二分探索木: 挿入
 * insert k: 二分探索木Tにキーkを挿入
 * print   : キーを木の中間順巡回と先行順巡回アルゴリズムで出力
*/

#include <bits/stdc++.h>
using namespace std;

struct Node;
struct Node {
    int key;
    Node* parent;   // 親へのポインタ
    Node* left;     // 左の子へのポインタ
    Node* right;    // 右の子へのポインタ
};

Node* root;
Node* NIL;

/// @brief 挿入
/// @param k キー
static void insert(int k)
{
    Node* y = NIL;      // xの親
    Node* x = root;     // 根
    Node* z;

    z = (Node*)malloc(sizeof(Node));
    z->key = k;         
    z->left = NIL;
    z->right = NIL;

    while (x != NIL) {
        y = x;          // 親を設定
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NIL) {
        root = z;
    } else {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

/// @brief 中間順巡回アルゴリズム
/// @param u 
static void inorder(Node* u)
{
    if (u == NIL) return;

    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
}

/// @brief 先行順巡回
/// @param u 
static void preorder(Node* u)
{
    if (u == NIL) return;

    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}

int main()
{
    int n, x;
    string command;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "insert") {
            cin >> x;
            insert(x);
        } else if (command == "print") {
            inorder(root);
            cout << '\n';
            preorder(root);
            cout << '\n';
        }
    }

    return 0;
}