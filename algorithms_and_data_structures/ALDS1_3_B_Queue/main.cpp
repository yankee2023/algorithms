#include <stdio.h>
#include <string.h>
#define LEN 100005

typedef struct Process {
    char name[100];
    int time;
} Process;

Process queue[LEN];
// キューの先頭の場所を指す
int head;
// キューの末尾 +1(最後の要素の1つ後ろ)を指す 
int tail;
int n;

/**
 * @brief キューに要素を追加
 * @param [in] x キューに追加する要素
*/
static void enqueue(Process x) {
    queue[tail] = x;
    tail = (tail + 1) % LEN;
}

/**
 * @brief キューから要素を取り出す
 * @return 一番古いProcess
*/
static Process dequeue() {
    Process x = queue[head];
    head = (head + 1) % LEN;
    return x;
}

static int min(int a, int b) {
    return a < b ? a : b;
} 

int main() {
    int elaps_time = 0, c;
    int quantum;
    Process u;

    /* すべてのプロセスを順番にエンキュー */
    scanf("%d %d", &n, &quantum);
    for (int i = 1; i <= n; i++) {
        scanf("%s", queue[i].name);
        scanf("%d", &queue[i].time);
    }
    head = 1;
    tail = n + 1;

    while (head != tail) {
        u = dequeue();
        c = min(quantum, u.time);   // quantumまたは必要な時間u.timeだけ処理を行う
        u.time -= c;                // プロセスの残りの時間を計算
        elaps_time += c;            // プロセスの経過時間を計算
        if (u.time > 0) {
            enqueue(u);             // 処理が完了していなければエンキュー
        } else {
            printf("%s %d\n", u.name, elaps_time);
        }
    }

    return 0;
}