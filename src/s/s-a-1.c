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

void initialize_list_randomly(int *list, int length, int max_num);

void write_file(int *list, int length, FILE *fp);


int main() {
    int list[LIST_SIZE];

    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        fatal(-1, "[X] Unknown error: Failed to open '%s'.", FILENAME)
    }

    printf("Generating a random integers...\n");
    initialize_list_randomly(list, LIST_SIZE, MAX_NUM);

    printf("Writing to the file...\n");
    write_file(list, LIST_SIZE, fp);

    print_green("[i] Succeeded to write the file!");

    fclose(fp);

    return 0;
}


void initialize_list_randomly(int *list, int length, int max_num) {
    for (int i = 0; i < length; i++) {
        list[i] = rand() % max_num + 1;
    }
}


void write_file(int *list, int length, FILE *fp) {
    for (int i = 0; i < length; i++) {
        fprintf(fp, "%d\n", list[i]);
    }

    fputs("", fp);
}
