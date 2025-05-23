#include <stdio.h>
#include <stdlib.h>

int count = 0; // カウント変数
int sort(int arr[], int left, int right);
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
}

void run_sort(int num) {
    int arr[num];
    for (int i = 0; i < num; i++) { // 配列の初期化
        arr[i] = rand() % 100; // ランダムな値を代入
    }
    sort(arr, 0, num - 1); // クイックソートを実行

    printf("交換回数(%d個): %d\n", num, count);
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
            count++; // カウントを増やす

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
