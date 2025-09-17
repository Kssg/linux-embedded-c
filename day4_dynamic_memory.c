#include <stdlib.h>
#include <stdio.h>

int main() {
    // *arr or arr[] ?
    int *arr = malloc(5 * sizeof(int));
    
    printf("Input 5 numbers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    printf("After realloc: \n");
    
    int *tmp = realloc(arr, 10 * sizeof(int));
    if (tmp == NULL) {
        free(arr);
        printf(stderr, "realloc failed\n");
        return 1;
    }

    arr = tmp;
    for (int i = 5; i < 10; i++) {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    free(arr);

    return 0;
}
