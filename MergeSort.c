#include<stdio.h>
#include<stdlib.h>

int  acceptVal();
int* acceptVals(int size);
void mergeSort(int* arr, int start, int end);
void merge(int * arr, int start, int mid, int end);
void quickSort(int * arr, int start, int end)
void printArray(int* arr, int size);

int acceptVal(){
    int val;
    printf("Enter the size of the array: ");
    scanf("%d", &val);
    return val;
}

int* acceptVals(int size){
    int i;
    int* out = (int *)calloc(size, sizeof(int));
    printf("Enter the values:\n");
    for (i=0; i<size; i++) {
        scanf("%d", &out[i]);
    }
    return out;
}

void mergeSort(int* arr, int start, int end) {
    if (start<end) {
        int mid = start+(end-start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int* arr, int start, int mid, int end) {
    int i, j, k;
    int a = mid - start;
    int b = end - mid;
    int left[a], right[b];

    for (i = 0; i<a; i++) 
        left[i] = arr[start + i];

    for (i = 0; i<b; i++) 
        right[i] = arr[mid + i + 1];

    i = 0;
    j = 0;
    k = start;

    while (i<a && j<b) {
        if (left[i]<=right[j])
            arr[k] = left[i++];
        else 
            arr[k] = right[j++];
        k++;
    }

    while (i<a) 
        arr[k++] = left[i++];

    while (j<b) 
        arr[k++] = right[j++];
}

void printArray(int* arr, int size){
    int i;
    for (i = 0; i<(size-1); i++) 
        printf("%d, ", arr[i]);
    printf("%d\n", arr[i]);
}

int main() {
    int * arr, size;
    size = acceptVal();
    arr = acceptVals(size);
    printf("\nBefore Sorting:\n");
    printArray(arr, size);
    printf("\nAfter sorting:\n");
    mergeSort(arr, 0, size);
    printArray(arr, size);
    return 0; 
}