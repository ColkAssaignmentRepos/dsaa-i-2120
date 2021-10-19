//
// Created by Manaki ITO on 2021/10/12.
//

#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 5000
#define MAX_NUM 10000
#define FILENAME "numbers.txt"

#define print_green(...) {printf("\x1b[32m"); printf(__VA_ARGS__); printf("\x1b[39m\n");}
#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}
#define blank() {printf("\n");}

void read_file(FILE *fp, int dist[], int length);

int lookup(int *list, int length, int query);


int main() {
    int list[LIST_SIZE];
    int search_target;
    int found_index;

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        fatal(-1, "[X] Unknown error: Failed to open '%s'.", FILENAME)
    }

    printf("Reading from the file...\n");
    read_file(fp, list, LIST_SIZE);
    print_green("[i] Succeeded to read the file!");

    printf("Please input number to look up: ");
    scanf("%d", &search_target);

    found_index = lookup(list, LIST_SIZE, search_target);

    if (found_index != -1) {
        printf("The number '%d' is located at the index: %d\n", search_target, found_index + 1);
    }
    else {
        printf("NO SUCH NUMBER FOUND IN THE FILE!\n");
    }

    fclose(fp);

    return 0;
}


void read_file(FILE *fp, int dist[], int length) {
    for (int i = 0; i < length; i++) {
        int retval = fscanf(fp, "%d", &dist[i]);

        if (retval == -1) {
            fatal(retval, "[X] Unknown error: Failed to read the file.")
        }
    }
}


int lookup(int *list, int length, int query) {
    for (int i = 0; i < length; i++) {
        if (list[i] == query) {
            return i;
        }
    }

    return -1;
}
