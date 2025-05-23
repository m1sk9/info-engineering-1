#include <stdio.h>

#define NUM 10
// 配列を整えて表示するマクロ
#define DISPLAY(arr) \
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) { \
        printf("%d%s", arr[i], (i < 9) ? ", " : ""); \
    } \
    printf("\n");

int sort(int arr[], int left, int right);

int main() {
    int arr[10] = {5, 2, 9, 1, 5, 6, 7, 3, 8, 4}; // データ (要素10個の配列)

    printf("ソート前の配列: ");
    DISPLAY(arr)

    sort(arr, 0, NUM - 1);

    printf("ソート後の配列: ");
    DISPLAY(arr)
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
