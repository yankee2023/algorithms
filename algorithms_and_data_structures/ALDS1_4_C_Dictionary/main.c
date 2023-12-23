#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define M   (1046527)
#define NIL (-1)
#define L   (14)

char H[M][L];

/**
 * @brief 文字から数字に変換
 * @param [in] ch 今回の入力文字
 * @return 1: A, 2: C, 3: G, 4: T, 0: それ以外 
*/
static int32_t get_char(char ch) {
    if (ch == 'A') {
        return 1;
    } else if (ch == 'C') {
        return 2;
    } else if (ch == 'G') {
        return 3;
    } else if (ch == 'T') {
        return 4;
    } else {
        return 0;
    }
}

/**
 * @brief 文字列から数値へ変換しkeyを生成
 * @param [in] str 任意の文字列
 * @return key
*/
static int64_t get_key(char str[]) {
    int64_t sum = 0, p = 1, i;
    for (i = 0; i < strlen(str); i++) {
        sum += p * (get_char(str[i]));
        p *= 5;
    }
    return sum;   
}

/**
 * @brief ハッシュ関数
 * @param [in] key キー
 * @return ハッシュ値
*/
static int32_t hash(int32_t key) {
    return key % M;
}

static int32_t h2(int32_t key) {
    return 1 + (key % (M -1));
}

/**
 * @brief ダブルハッシュ関数
 * 衝突が怒らなかった最初のハッシュ値を返す
 * @param [in] key キー
 * @param [in] i 衝突が発生して次のハッシュ値を計算した回数
 * @return ハッシュ値
*/
static int32_t double_hash(int32_t key, int32_t i) {
    return (hash(key) + i * h2(key)) % M;
}

/**
 * @brief 辞書に文字列を追加
 * @param [in] str 追加したい文字列
 * @return 0: 挿入, 1: すでに存在
*/
static int32_t insert(char str[]) {
    int64_t key, i, h;
    key = get_key(str);     // 文字列を数値へ変換
    for (i = 0; ; i++) {
        h = double_hash(key, i);
        if (strcmp(H[h], str) == 0) {
            return 1;
        } else if (strlen(H[h]) == 0) {
            strcpy(H[h], str);
            return 0;
        }
    }
    return 0;
}

/**
 * @brief 辞書に文字列が存在するかの処理
 * @param [in] str 探したい文字列キー
 * @return 0: NOT_FOUND, 1: FIND
*/
static int32_t find(char str[]) {
    int64_t key, i, h;
    key = get_key(str);     // 文字列を数値へ変換
    for (i = 0; ; i++) {
        h = double_hash(key, i);
        if (strcmp(H[h], str) == 0) {
            return 1;
        } else if (strlen(H[h]) == 0){
            return 0;
        }
    }
    return 0;
}

int32_t main() {
    int32_t n, h;
    char str[L], com[9];
    for (int32_t i = 0; i < M; i++) {
        H[i][0] = '\0';
    }
    scanf("%d", &n);
    
    for (int32_t i = 0; i < n; i++) {
        scanf("%s %s", com, str);

        if (com[0] == 'i') {
            insert(str);
        } else {
            if (find(str)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }

    return 0;
}