//
// Edited by Manaki ITO on 2021/10/19.
//

#include <stdio.h>
#include<stdlib.h>
#include <string.h>


int search(const int a[], int n, int key) {
    int *searching = (int *) malloc(sizeof (int) * n);
    memcpy(searching, a, (sizeof(int) * n));

    searching[n - 1] = key;

    int i = 0;
    while (searching[i] != key) {
        i++;
    }

    if (i == (n - 1)) {
        return -1;
    }

    return i;
}


int main(void) {
    int i, ky, idx;
    int x[7];
    int nx = sizeof(x) / sizeof(x[0]);

    printf("%d個の整数を入力してください: \n", nx - 1);
    for (i = 0; i < nx - 1; i++) { /* 注意: 値を読み込むのは nx 個ではない */
        printf("x[%d]:", i);
        scanf("%d", &x[i]);
    }

    printf("探索値: ");
    scanf("%d", &ky);

    idx = search(x, nx, ky); /* 配列xから値がkyである要素を線形探索 */

    if (idx == -1)
        puts("一致する要素はありません。");
    else
        printf("%dは%d番目にあります。\n", ky, idx + 1);

    return 0;
}
