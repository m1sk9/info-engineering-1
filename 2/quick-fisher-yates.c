#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TRIALS 20 // 試行回数

int count = 0; // カウント変数

void shuffle(int arr[], int n);
int sort(int arr[], int left, int right);
void run_sort(int num);

int main() {
    srand((unsigned)time(NULL)); // 乱数の初期化

    for (int num = 100; num <= 1000; num += 100) {
        printf("データ数: %d\n", num);
        run_sort(num);
    }

    return 0;
}

// Fisher-Yates シャッフル
void shuffle(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// クイックソートを20回実行し、交換回数と平均値を計算
void run_sort(int num) {
    int arr[num];
    int total_count = 0;

    for (int trial = 0; trial < NUM_TRIALS; trial++) {
        // 配列の初期化
        for (int i = 0; i < num; i++) {
            arr[i] = i + 1;
        }

        // Fisher-Yates シャッフルで配列をランダム化
        shuffle(arr, num);

        // クイックソート
        count = 0; // カウントをリセット
        sort(arr, 0, num - 1);

        printf("試行 %d: 交換回数 = %d\n", trial + 1, count);
        total_count += count;
    }

    // 平均値を計算して出力
    double average = (double)total_count / NUM_TRIALS;
    printf("平均交換回数: %.2f\n\n", average);
}

// クイックソート
int sort(int *arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];
    int temp;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            count++; // 交換回数を増加
            i++;
            j--;
        }
    }

    if (left < j) {
        sort(arr, left, j);
    }
    if (i < right) {
        sort(arr, i, right);
    }

    return 0;
}
