#include <stdio.h>
#include <stdlib.h>

typedef struct _stack {
    int data;
    struct _stack *next;
} stack;

void init(void); /* 初期化 */
void add(void); /* データ追加 */
void delete(void); /* データ削除 */
void display(void); /* データ表示 */
void release(void); /* データ開放 */
void push(stack *s, int n); /* データ追加 */
int pop(void); /* データ取り出し */

stack *head;


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
                delete();
                break;
            case 3:
                display();
                break;
        }
    }
    release();

    return (0);
}


void init(void) {
    head = NULL;
}


void add(void) {
    stack *s;
    int n;

    s = (stack *) malloc(sizeof(stack));
    if (s == NULL) {
        printf("メモリの確保失敗.\n");
        return;
    }

    printf("整数を入力してください.\n");
    scanf("%d", &n);
    push(s, n);
    printf("追加しました: %d\n", n);
}


void delete(void) {
    printf("取り出しました: %d\n", pop());
}


void display(void) {
    stack *s;
    s = head;

    printf("---\n");

    while (s != NULL) {
        printf("%d\n", s->data);
        s = s->next;
    }

    printf("---\n");
}


void release(void) {
    stack *s, *tmp;

    s = head;
    tmp = head;

    while (s != NULL) {
        tmp = s->next;
        free(s);
        s = tmp;
    }
}


void push(stack *s, int n) {
    s->data = n;
    s->next = head;

    head = s;
}


int pop(void) {
    stack *s;
    int n;

    s = head;

    n = s->data;
    head = s->next;
    free(s);

    return n;
}
