//
// Created by Manaki ITO on 2021/10/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_LENGTH 5
#define MAX_NAME_LENGTH 64
#define MAX_AGE 18

typedef struct{
    int age;
    char name[MAX_NAME_LENGTH];
} person_p;

void initialize_list(person_p *list, int length, int max_num);
void show_list(person_p *list, int length);
int lookup(person_p *list, int length, char *query);

const char NAMES[LIST_LENGTH][MAX_NAME_LENGTH] = {"Chino", "Cocoa", "Maya", "Megu", "Mocha"};


int main () {
    person_p list[LIST_LENGTH];
    char query[MAX_NAME_LENGTH];
    int found_index;

    // 5 人分の名前と年齢でリストを初期化
    initialize_list(list, LIST_LENGTH, MAX_AGE);
    show_list(list, LIST_LENGTH);

    printf("Please input name of a person to look up: ");
    scanf("%s", query);

    found_index = lookup(list, LIST_LENGTH, query);

    if (found_index != -1) {
        printf("'%s' is located at the index: %d\n", query, found_index + 1);
    }
    else {
        printf("NO SUCH PERSON FOUND IN THE LIST!\n");
    }

    return 0;
}


void initialize_list(person_p *list, int length, int max_num) {
    for (int i = 0; i < length; i++) {
        strcpy(list[i].name, NAMES[i]);
        list[i].age = rand() % max_num + 1;
    }
}


void show_list(person_p *list, int length) {
    printf("{");
    for (int i = 0; i < length; i++) {
        printf("%s %d", list[i].name, list[i].age);

        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}


int lookup(person_p *list, int length, char *query) {
    for (int i = 0; i < length; i++) {
        if (strcmp(list[i].name, query) == 0) {
            return i;
        }
    }

    return -1;
}
