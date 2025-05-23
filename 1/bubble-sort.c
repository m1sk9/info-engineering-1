#include <stdio.h>

// 配列を整えて表示するマクロ
#define DISPLAY(arr) \
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) { \
        printf("%d%s", arr[i], (i < 9) ? ", " : ""); \
    } \
    printf("\n");

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6, 7, 3, 8, 4}; // データ (要素10個の配列)
    int i;
    int j;
    int temp = 0;

    printf("ソート前の配列: ");
    DISPLAY(arr)

    for (i = 0; i < 10; i++) { // 外側のループ
        for (j = 0; j < 9 - i; j++) { // 内側のループ
            if (arr[j] > arr[j + 1]) { // 隣接要素の比較
                temp = arr[j]; // 要素の入れ替え
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("ソート後の配列: ");
    DISPLAY(arr)

    return 0;
}
