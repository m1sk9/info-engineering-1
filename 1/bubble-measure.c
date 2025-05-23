#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define REPEAT 100000
#define NUM 500

int main() {
    int arr[NUM];
    int i;
    int j;
    int temp = 0;
    clock_t start, end;
    double result;

    start = clock(); // 計測開始

    for (int r = 0; r < REPEAT; r++) { // REPEAT 回繰り返し
        for (i = 0; i < NUM; i++) { // 配列の初期化
            arr[i] = rand() % 100; // ランダムな値を代入
        }
        for (i = 0; i < NUM; i++) { // 外側のループ
            for (j = 0; j < NUM - 1 - i; j++) { // 内側のループ
                if (arr[j] > arr[j + 1]) { // 隣接要素の比較
                    temp = arr[j]; // 要素の入れ替え
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    end = clock(); // 計測終了

    result = ((double) end - start) / CLOCKS_PER_SEC; // 経過時間を計算
    printf("Time:  %.30fsec\n", result);
    printf("(%.30fsec per iteration)", result / REPEAT);

    return 0;
}
