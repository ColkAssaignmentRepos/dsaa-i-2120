//
// Created by Manaki ITO on 2021/10/12.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10000
#define FILENAME "numbers.txt"

#define print_green(...) {printf("\x1b[32m"); printf(__VA_ARGS__); printf("\x1b[39m\n");}
#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}

typedef struct liner_int {
    int data;
    struct liner_int *next;
} liner_int_t;

liner_int_t *malloc_intptr();

void free_intptr(liner_int_t *head);

void append(liner_int_t **head, liner_int_t **p);

void read_file(FILE *fp, liner_int_t **head);

liner_int_t *lookup(liner_int_t *head, int query);


int main() {
    liner_int_t *head = NULL;

    int search_target;
    liner_int_t *found;

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        fatal(-1, "[X] Unknown error: Failed to open '%s'.", FILENAME)
    }

    printf("Reading from the file...\n");
    read_file(fp, &head);
    print_green("[i] Succeeded to read the file!");

    printf("Please input number to look up: ");
    scanf("%d", &search_target);

    found = lookup(head, search_target);

    if (found == NULL) {
        printf("NO SUCH NUMBER FOUND IN THE FILE!\n");
    } else {
        printf("The number '%d' is located at the address: %p\n", search_target, found);
    }

    fclose(fp);
    free_intptr(head);

    return 0;
}


liner_int_t *malloc_intptr() {
    liner_int_t *intsp;

    intsp = (liner_int_t *) malloc(sizeof(liner_int_t));
    if (intsp == NULL) {
        fatal(-1, "[X] Unknown error: failed to secure memory.")
    }

    return intsp;
}


void free_intptr(liner_int_t *head) {
    liner_int_t *p = head;
    liner_int_t *tmp = NULL;

    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}


void append(liner_int_t **head, liner_int_t **p) {
    (*p)->next = *head;
    *head = *p;
}


void read_file(FILE *fp, liner_int_t **head) {
    int temp;
    liner_int_t *pLinerIntTmp = NULL;

    while (fscanf(fp, "%d", &temp) != EOF) {
        pLinerIntTmp = malloc_intptr();
        pLinerIntTmp->data = temp;

        append(head, &pLinerIntTmp);
    }
}


liner_int_t *lookup(liner_int_t *head, int query) {
    liner_int_t *p = head;

    while (p != NULL) {
        if (p->data == query) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}
