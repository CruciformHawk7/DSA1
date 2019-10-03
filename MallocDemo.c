#include<stdio.h>
#include<stdlib.h>

int * createIntArray(int size) {
    return (int *)malloc(size*sizeof(int));
}

int * createIntArrayC(int size) {
    return (int *)calloc(size, sizeof(int));
}

void printIntArray(int* arrayPtr, int size) {
    int i;
    for (i=0; i<(size-1); i++) 
        printf("%d, ", arrayPtr[i]);
    printf("%d\n", arrayPtr[i]);
}

void sortArray(int * arrayPtr, int size) {
    int i, j, t;
    size;
    for (i=0; i<size; i++) {
        for (j=0; j<(size-i-1); j++) {
            if (arrayPtr[j]>arrayPtr[j+1]) {
                t = arrayPtr[j];
                arrayPtr[j] = arrayPtr[j+1];
                arrayPtr[j+1] = t;
            }
        }
    }
}

int main() {
    int *x, *y;
    int i, n, t;
    printf("Enter the length of array: ");
    scanf("%d", &n);
    x = createIntArray(n);
    y = createIntArrayC(n);
    printf("Enter the values:\n");
    for (i=0; i<n; i++) {
        scanf("%d", &t);
        x[i] = t;
        y[i] = t;
    }
    printf("\nValues are: \n");
    printIntArray(x,n);
    sortArray(x,n);
    printf("Sorted:\n");
    printIntArray(x,n);
    printf("\nContiguos array: \n");
    printIntArray(y,n);
    sortArray(y,n);
    printf("Sorted:\n");
    printIntArray(y,n);
    return 0;
}