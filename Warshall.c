#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 4

bool* warshalls     (bool* array, int m);
bool* acceptArray   (int n);
int  acceptNumber   ();
void printArray     (bool* array, int size);

bool* warshalls(bool* arr, int m) {
    bool* array = arr;
    int i, j, k;
    for(i=0; i<m; i++) {
        for(j=0; j<m; j++) {
            for (k=0; k<m; k++) {
                array[j*m+k] = array[j*m+k] || (array[j*m+i] && array[i*m+k]);
            }
        }
    }
    return array;
}

bool* acceptArray(int n) {
    int i, j;
    int temp;
    bool* p = (bool *)malloc(n*n*sizeof(bool));
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (i==j) { 
                p[i*n+j] = false;
                continue;
            } else {
                printf("\nEnter %d -> %d: ", i, j);
                scanf("%d", &temp);
                if (temp==0) p[i*n+j] = false;
                else p[i*n+j] = true;
            }
        }
    }
    printArray(p,n);
    return p;
}

void printArray(bool* array, int size) {
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
    bool *x = acceptArray(SIZE);
    x=warshalls(x, SIZE);
    printArray(x, SIZE);
}