#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10
// 配列を整えて表示するマクロ
#define DISPLAY(arr) \
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) { \
        printf("%d%s", arr[i], (i < 9) ? ", " : ""); \
    } \
    printf("\n");

void shuffle(int arr[], int n);

int main(void) {
    int arr[NUM];
    int i;
    int n;

    srand((unsigned)time(NULL)); // 乱数の初期化
    for (i = 0; i < NUM; i++) {
        arr[i] = i + 1; // 配列の初期化
    }

    printf("シャッフル前の配列: ");
    DISPLAY(arr); // 初期状態の表示

    shuffle(arr, NUM); // シャッフル実行

    printf("シャッフル後の配列: ");
    DISPLAY(arr); // シャッフル結果の表示

    return 0;
}

// Fisher-Yates
void shuffle(int arr[], int n) {
    unsigned int i;
    unsigned int j;
    int temp;

    i = n - 1;
    while (i > 0) {
        j = rand() % (i + 1);
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;

        i--;
    }
}
