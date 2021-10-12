//
// Created by Manaki ITO on 2021/10/12.
//

//
// Created by Manaki ITO on 2021/10/12.
//

#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 10
#define MAX_NUM 100

void initialize_list_randomly(int *list, int length, int max_num);
void show_list(int *list, int length);
int lookup(int *list, int length, int query);


int main () {
    int list[LIST_SIZE];
    int search_target;
    int found_index;

    // 1 ~ 100 のランダムな値で配列を初期化
    initialize_list_randomly(list, LIST_SIZE, MAX_NUM);
    show_list(list, LIST_SIZE);

    printf("Please input number to look up: ");
    scanf("%d", &search_target);

    found_index = lookup(list, LIST_SIZE, search_target);

    if (found_index != -1) {
        printf("The number '%d' is located at the index: %d\n", search_target, found_index + 1);
    }
    else {
        printf("NO SUCH NUMBER FOUND IN THE LIST!\n");
    }

    return 0;
}


void initialize_list_randomly(int *list, int length, int max_num) {
    for (int i = 0; i < length; i++) {
        list[i] = rand() % max_num + 1;
    }
}


void show_list(int *list, int length) {
    printf("{");
    for (int i = 0; i < length; i++) {
        printf("%d", list[i]);

        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}


int lookup(int *list, int length, int query) {
    for (int i = 0; i < length; i++) {
        if (list[i] == query) {
            return i;
        }
    }

    return -1;
}
