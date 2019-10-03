#include<stdio.h>
#include<stdlib.h>

void warshalls(int* array, int m);
int* acceptArray(int n);
int  acceptNumber();
void printArray(int* array, int size);

void warshalls(int* array, int m) {
    int i, j, k;
    for(i=0; i<m-1; i++) {
        for(j=0; j<m; j++) {
            if (array[i*m]==0) {
                continue;
            } else {

            }
        }
    }
}

int* acceptArray(int n) {
    int i, j;
    int* p = (int *)malloc(n*n*sizeof(int));
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (i==j) { 
                p[i*n+j] = 0;
                continue;
            } else {
                printf("\nEnter %d -> %d", i, j);
                scanf("%d", &p[i*n+j]);
            }
        }
    }
    printArray(p,n);
}

void printArray(int* array, int size) {
    int i, j;
    printf("\n");
    for(i=0;i<size;i++) {
        for (j=0 ;j<size;j++) {
            printf("%d ", array[i*size+j]);
        }
        printf("\n");
    }
}

void main() {
    int *x = acceptArray(4);
}