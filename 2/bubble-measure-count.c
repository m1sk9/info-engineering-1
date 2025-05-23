#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int count = 0; // カウント変数
void run_sort(int num);

int main() {
    run_sort(100);
    run_sort(200);
    run_sort(300);
    run_sort(400);
    run_sort(500);
    run_sort(600);
    run_sort(700);
    run_sort(800);
    run_sort(900);
    run_sort(1000);
    return 0;
}

void run_sort(int num) {
    int arr[num];
    int i;
    int j;
    int temp = 0;

    for (i = 0; i < num; i++) { // 配列の初期化
        arr[i] = rand() % 100; // ランダムな値を代入
    }
    for (i = 0; i < num; i++) { // 外側のループ
        for (j = 0; j < num - 1 - i; j++) { // 内側のループ
            if (arr[j] > arr[j + 1]) { // 隣接要素の比較
                temp = arr[j]; // 要素の入れ替え
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                count++; // カウントを増やす
            }
        }
    }

    printf("交換回数(%d個): %d\n", num, count);
}
