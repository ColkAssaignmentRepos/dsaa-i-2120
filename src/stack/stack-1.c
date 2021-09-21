#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void init(void); /* 初期化 */
void display(void); /* データ表示 */
void add(void); /* データ追加 */
void delete(void); /* データ削除 */
void push(int n); /* データ追加 */
int pop(void); /* データ取り出し */
int isFull(void); /* 満杯のチェック */
int isEmpty(void); /* 空のチェック */

int stack[SIZE];
int sp;

int main(void) {
    int res;

    init();

    while (1) {
        printf("1--追加 2--削除 3--表示 0--終了\n");
        scanf("%d", &res);

        if (res == 0) {
            break;
        }

        switch (res) {
            case 1:
                add();
                break;
            case 2:
                delete():
                break;
            case 3:
                display();
                break;
        }
    }

    return (0);
}


void init(void) { /* 初期化 */
    sp = 0;
}


void display(void) { /* データ表示 */
    int i;

    printf("---\n");

    for (i = sp - 1; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    printf("---\n");
}


void add(void) { /*データ追加 */
    int n;

    if (isFull()) {
        return;
    }

    printf("整数を入力してください.\n");
    scanf("%d", &n);
    push(n);
    printf("%d追加しました.\n", n);
}


void delete(void) { /* データ削除 */
    if (isEmpty()) {
        return;
    }
    printf("%dを取り出しました.\n", pop());
}


void push(int n) { /* データ追加 */
    // TODO: Fill (ア)
    // stack[__(ア)__] = n;
}


void pop(void) { /* データ取り出し */
    // TODO: Fill (イ)
    // return (stack[__(イ)__]);
}


/* スタックが満杯かどうかのチェック */
int isFull(void) {
    if (sp >= SIZE) {
        printf("スタックが満杯です.\n");
        return 1;
    }

    return 0;
}


/* スタックが空かどうかのチェック */
int isEmpty(void) {
    if (sp <= 0) {
        printf("スタックは空です.\n");
        return 1:
    }
    return 0;
}
