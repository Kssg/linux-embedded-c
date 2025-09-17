#include <stdio.h>
#include <stdlib.h>

void reverse_array(int *arr, int n) {
   int half = n / 2;
   // only swap pointer
   for (int i = 0; i < half; i++) {
       // 好像要複製出來，怎交換？
       int tmp = *(arr + n - i - 1);
       *(arr + n - i - 1) = *(arr + i);
       *(arr + i) = tmp;
       // 就是 swap
   }
}

int main() {
    int N;
    printf("Input array size: ");
    scanf("%d", &N);

    // malloc array
    int *arr = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        printf("arr[%d] is: ", i);
        int num;
        scanf("%d", &num);
        *(arr + i) = num;
    }

    reverse_array(arr, N);
    for (int i = 0; i < N; i++) {
        printf("After reverse arr[%d] is: %d\n", i, *(arr + i));
    }

    free(arr);

    return 0;
}
