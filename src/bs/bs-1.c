#include <stdio.h>

#define SIZE 10


int main() {
    int data[SIZE] = {3, 5, 7, 13, 15, 21, 23, 26, 31, 34};
    int n, p, q, m;

    printf("探索値の入力.\n");
    scanf("%d", &n);
    p = 0;
    q = 9;

    while (p <= q) {
        m = (p + q) / 2;

        if (data[m] == n) {
            printf("%d 番目に %d が見つかりました。\n", m + 1, data[m]);
            return 0;
        } else if (data[m] < n) {
            p = m + 1;
        } else {
            q = m - 1;
        }
    }

    printf("見つかりませんでした。\n");
    return 0;
}
