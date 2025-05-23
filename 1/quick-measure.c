#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 500
#define REPEAT 1000000

// 配列を整えて表示するマクロ
#define DISPLAY(arr) \
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) { \
        printf("%d%s", arr[i], (i < 9) ? ", " : ""); \
    } \
    printf("\n");

int sort(int arr[], int left, int right);

int main() {
    int arr[NUM];
    clock_t start, end;
    double result;

    start = clock(); // 計測開始

    for (int r = 0; r < REPEAT; r++) { // REPEAT 回繰り返し
        for (int i = 0; i < NUM; i++) { // 配列の初期化
            arr[i] = rand() % 100; // ランダムな値を代入
        }

        sort(arr, 0, NUM - 1); // クイックソートを実行
    }

    end = clock(); // 計測終了

    result = ((double) end - start) / CLOCKS_PER_SEC; // 経過時間を計算
    printf("Time:  %.30fsec\n", result);
    printf("(%.30fsec per iteration)\n", result / REPEAT);

    return 0;
}

int sort(int *arr, int left, int right) {
    int i = left;
    int j = right;
    int x = arr[(left + right) / 2]; // 基準値を中央値に設定
    int temp;

    while (i <= j) {
        while (arr[i] < x) { // 基準値より小さい要素を探す
            i++;
        }
        while (arr[j] > x) { // 基準値より大きい要素を探す
            j--;
        }
        if (i <= j) { // iとjが交差していない場合
            // 要素の入れ替え
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }

    if (left < j) {
        sort(arr, left, j); // 左側を再帰呼び出し
    }

    if (i < right) {
        sort(arr, i, right); // 右側を再帰呼び出し
    }

    return 0;
}
