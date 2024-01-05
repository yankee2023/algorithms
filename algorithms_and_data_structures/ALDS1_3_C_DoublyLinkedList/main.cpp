#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
    int key;
    Node* prev;
    Node* next;
};

Node* nil;

static void printList() {
    Node* current = nil->next;
    int isf = 0;
    while (true) {
        if (current == nil) {
            break;
        }

        if (isf > 0) {
            printf(" ");
        }
        isf++;
        printf("%d", current->key);
        current = current->next;
    }
    printf("\n");
}

/**
 * @brief グローバル変数nilの初期化
*/
static void init() {
    nil = (Node*)malloc(sizeof(Node));
    nil->prev = nil;
    nil->next = nil;
}

/**
 * @brief 双方向リストへの要素の挿入
 * @param [in] key キー
*/
static void insert(int key) {
    Node* x = (Node*)malloc(sizeof(Node));
    x->key = key;
    // 番兵の直後に要素を追加
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

/**
 * @brief 双方向リストの要素の探索
 * リストの先頭要素から順に探索
 * @param [in] key キー
 * @return 探索リスト
*/
Node* listSerarch(int key) {
    // 番兵の次の要素から辿る
    Node* current = nil->next;
    while (current != nil && current->key != key) {
        current = current->next;
    }
    return current;
} 

/**
 * @brief 双方向リストの要素の削除
 * @param [in] target 削除対象
*/
static void deleteNode(Node* target) {
    if (target == nil) {
        // targetが番兵の場合は処理しない
        return;
    }

    // 一つ前のノードと一つ先のノードを連結
    target->prev->next = target->next;
    target->next->prev = target->prev;
    free(target);
}

static void deleteFirst() {
    deleteNode(nil->next);
}

static void deleteLast() {
    deleteNode(nil->prev);
}

/**
 * @brief 検索したノードを削除
*/
static void deleteKey(int key) {
    deleteNode(listSerarch(key));
}

int main() {
    int key, n;
    int size = 0;
    char com[20];
    int np = 0, nd = 0;
    scanf("%d", &n);
    init();

    for (int i = 0; i < n; i++) {
        scanf("%s%d", com, &key);
        if (com[0] == 'i') {                // insert
            insert(key);
            np++;
            size++;
        } else if (com[0] == 'd') {
            if (strlen(com) > 6) {
                if (com[6] == 'F') {        // deleteFirst
                    deleteFirst();
                } else if (com[6] == 'L') { // deleteLast
                    deleteLast();
                }
            } else {                        // deleteKey
                deleteKey(key);
                nd++;
            }
            size--;
        }
    }
    
    printList();
    
    return 0;
}