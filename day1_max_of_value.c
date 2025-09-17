#include <stdio.h>
#define N 5

int max_of_three(int a, int b, int c) {
    int max = a > b ? a : b;
    max = a > c ? a : c;
    return max;
}

int max_in_array(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int main() {
    int arr[N];
    printf("請輸入 %d 個數字：\n", N);
    for (int i = 0; i < N; i++) {
        printf("Input numbers: ");
        scanf("%d", &arr[i]);
    }

    printf("Max value is: %d\n", max_in_array(arr, N));

    return 0;
}
