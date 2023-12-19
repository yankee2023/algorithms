#include <bits/stdc++.h>
using namespace std;

#define MAX     100000
#define NIL     -1

typedef struct {
    int parent;
    int left;
    int right;
} Node;

Node Tree[MAX];
int n;
int Depth[MAX];     // 深さ
int Height[MAX];    // 高さ

static void set_depth(int u, int d)
{
    if (u == NIL) {
        return;
    }

    Depth[u] = d;
    set_depth(Tree[u].left, d + 1);
    set_depth(Tree[u].right, d + 1);
}

static int set_height(int u)
{
    int h1 = 0, h2 = 0;
    if (Tree[u].left != NIL) {
        h1 = set_height(Tree[u].left) + 1;
    }
    if (Tree[u].right != NIL) {
        h2 = set_height(Tree[u].right) + 1;
    }

    return Height[u] = (h1 > h2 ? h1 : h2);
}

static int get_sibling(int u)
{
    if (Tree[u].parent == NIL) {
        return NIL;
    }
    if(Tree[Tree[u].parent].left != u && Tree[Tree[u].parent].left != NIL) {
        return Tree[Tree[u].parent].left;
    }
    if(Tree[Tree[u].parent].right != u && Tree[Tree[u].parent].right != NIL) {
        return Tree[Tree[u].parent].right;
    }
    return NIL;
}

static void print(int u)
{
    cout << "node " << u << ": ";
    cout << "parent = " << Tree[u].parent  << ", ";
    cout << "sibling = " << get_sibling(u) << ", ";
    int deg = 0;
    if (Tree[u].left != NIL) {
        deg++;
    }
    if (Tree[u].right != NIL) {
        deg++;
    }
    cout << "degree = " <<  deg << ", ";
    cout << "depth = " << Depth[u] << ", ";
    cout << "height = " << Height[u] << ", ";

    if (Tree[u].parent == NIL) {
        cout << "root" << endl;
    } else if (Tree[u].left == NIL && Tree[u].right ==NIL) {
        cout << "leaf" << endl;
    } else {
        cout << "internal node" << endl;
    }
    
    
}

int main()
{
    int n;
    cin >> n;

    // 最初にNILで初期化すれば、
    // 子を持たない場合の-1の処理を行わなくてよい
    for (int i = 0; i < n; i++) {
        Tree[i].parent = NIL;
    }
    

    int id, left , right;
    for (int i = 0; i < n; i++) {
        cin >> id >> left >> right;
        Tree[id].left = left;
        Tree[id].right = right;
        if (left != NIL) {
            Tree[left].parent = id;
        }
        if (right != NIL) {
            Tree[right].parent = id;
        }
    }

    int root = 0;
    for (int i = 0; i < n; i++) {
        if (Tree[i].parent == NIL) {
            root = i;
        }
    }
    
    set_depth(root, 0);
    set_height(root);

    for (int i = 0; i < n; i++) {
        print(i);
    }
    
    return 0;
}