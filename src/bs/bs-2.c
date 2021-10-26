#include <stdio.h>
#include <string.h>

#define SIZE 10

void display(int *data, int length);

void sort_with_bubble(int *array, int *result, int length);

int lookup_with_bs(int *array, int length, int query);


int main() {
    int data[SIZE] = {23, 2, 15, 7, 19, 10, 13, 4, 1, 27};
    int sorted[SIZE];
    int query;
    int found_idx = -1;

    printf("探索値の入力.\n");
    scanf("%d", &query);

    sort_with_bubble(data, sorted, SIZE);

    printf("ソート後の配列;\n");
    display(sorted, SIZE);

    found_idx = lookup_with_bs(sorted, SIZE, query);

    if (found_idx == -1) {
        printf("見つかりませんでした。\n");
    } else {
        printf("%d 番目に %d が見つかりました。\n", found_idx + 1, sorted[found_idx]);
    }
}


void display(int *data, int length) {
    int i;
    printf("{");
    for (i = 0; i < length; i++) {
        printf("%d, ", data[i]);
    }
    printf("}");
    printf("\n");
}


void sort_with_bubble(int *array, int *result, int length) {
    // result は sizeof(int) * length 分だけの領域が確保されていると仮定している。
    int is_sorted = 0;
    int tmp;
    memcpy(result, array, sizeof(int) * length);

    while (1) {
        for (int i = 0; i < length - 1; i++) {
            if (result[i] > result[i + 1]) {
                break;
            }

            if (i == length - 1 - 1) {
                is_sorted = 1;
            }
        }

        if (is_sorted) {
            break;
        }

        for (int i = 0; i < length - 1; i++) {
            if (result[i] > result[i + 1]) {
                tmp = result[i + 1];

                result[i + 1] = result[i];
                result[i] = tmp;
            }
        }
    }
}


int lookup_with_bs(int *array, int length, int query) {
    int n, p, q, m;
    n = query;
    p = 0;
    q = length;

    while (p <= q) {
        m = (p + q) / 2;

        if (array[m] == n) {
            return m;
        } else if (array[m] < n) {
            p = m + 1;
        } else {
            q = m - 1;
        }
    }

    return -1;
}
