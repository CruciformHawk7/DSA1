#include<stdio.h>
#include<stdlib.h>

int linearSearch(int * number, int size, int num);
int binarySearch(int * number, int start, int end, int num);
int displayMenu();
int acceptVal();
int * acceptArray();
int * copyArray(int * inputArray, int size);
void printArray(int* array, int size);
void sort(int * arr, int size);

int linearSearch(int * number, int size, int num) {
    int i;
    for (i=0; i<size; i++) {
        if (number[i]==num) return (i+1);
    }
    return -1;
}

int binarySearch (int * number, int start, int end, int num) {
    if (end>=1) {
        int mid = start + (end - start)/2;
        if (number[mid]>num) return binarySearch(number, start, mid-1, num);
        else if (number[mid]==num) return (mid+1);
        else return binarySearch(number, mid+1, end, num);
    }
    else return -1;
}

int displayMenu() {
    int choice;
    printf("\nChoose:\n1. Linear\n2. Binary\n3. Exit\n");
    scanf("%d", &choice);
    return choice;
}


int acceptVal() {
    int val;
    printf("\nEnter a number to search: ");
    scanf("%d", &val);
    return val;
}

int * acceptArray(int *size) {
    int * arr;
    int n, i;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n*sizeof(int));
    printf("Enter the values: ");
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    *size = n;
    return arr;
}

int * copyArray(int * inputArray, int size) {
    int i = 0;
    int *copyArr = (int *)malloc(size*sizeof(int));
    for (i=0; i<size; i++) {
        copyArr[i] = inputArray[i];
    }
    return copyArr;
}

void printArray(int * array, int size) {
    int i;
    printf("\n");
    for (i=0; i<size-1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d", array[i]);
}

void sort(int * arr, int size) {
    int i, j, t;
    for (i=0; i<size; i++) {
        for (j=0; j<size-i; j++) {
            if (arr[j]>arr[j+1]) {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

int main() {
    int choice, size, number, another;
    int *arr1, *arr2;
    arr1 = acceptArray(&size);
    arr2 = copyArray(arr1, size);
    sort(arr2, size);
    printArray(arr1, size);
    while(1) {
        choice = displayMenu();
        if (choice == 1) {
            another = linearSearch(arr1, size, acceptVal());
            if (another == -1) printf("That number isn't in the array");
            else printf("That number was found at %d", another);
        } else if (choice == 2) {
            printf("Array will be sorted to: ");
            printArray(arr2, size);
            number = binarySearch(arr2, 0, size, acceptVal());
            if (number == -1) printf("That number isn't in the array");
            else printf("That number was found at %d", number);
        } else {
            return 0;
        }
    }
    return 0;
}