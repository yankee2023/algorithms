#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int top, S[1000];

/**
 * @brief PUSH
 * topを加算してからその位置へ挿入
*/
void push(int x) {
    top++;
    S[top] = x;
}

/**
 * @brief POP
 * @return topが指していた要素を返す
*/
int pop() {
    top--;
    return S[top+1];
}

int main() {
    int a, b;
    top = 0;
    char s[100];

    while (scanf("%s", s) != EOF) {
        if ('+' == s[0]) {
            a = pop();
            b = pop();
            push(a + b);
        } else if ('-' == s[0]) {
            b = pop();
            a = pop();
            push(a - b);
        } else if ('*'  == s[0]) {
            a = pop();
            b = pop();
            push(a * b);
        } else {
            push(atoi(s));
        }
    }    
    
    printf("%d\n", pop());

    return 0;
}