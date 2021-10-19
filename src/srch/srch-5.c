//
// Edited by Manaki ITO on 2021/10/19.
//

#include <stdio.h>
#include <string.h>


int search(const int a[], int n, int key, int *found_index) {
    int founds = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            found_index[founds] = i;
            founds++;
        }
    }

    return founds;
}


void show_result(int key, int founds, int *found_index) {
    if (founds <= 0) {
        puts("一致する要素はありません。");
        return;
    }

    printf("%dを次の添字で見つけました:\n{", key);
    for (int i = 0; i < founds; i++) {
        printf("%d, ", found_index[i]);
    }
    puts("}");
}


int main(void) {
    int i, ky, founds;
    int x[7];
    int found_index[7];
    int nx = sizeof(x) / sizeof(x[0]);

    memset(found_index, -1, sizeof(int) * nx);

    printf("%d個の整数を入力してください: \n", nx);
    for (i = 0;i < nx; i++) {
        printf("x[%d]:", i);
        scanf("%d", &x[i]);
    }

    printf("探索値: ");
    scanf("%d", &ky);

    founds = search(x, nx, ky, found_index);

    show_result(ky, founds, found_index);

    return 0;
}
