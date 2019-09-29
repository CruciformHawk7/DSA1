/*
 * A simple program to emulate Dijkstra's Algorithm
 * Using C
 */

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int weight;
    char name;
    int nextsize;
    struct Node* next[20];
};

typedef struct Node Node;

void printPath(Node *paths, int size) {
    int i, j;
    //Node traverser;
    for (i=0; i<size; i++) {
        if (paths[i].nextsize!=0) {
            for (j = 0; j<paths[i].nextsize; j++) 
            printf("%c-[%d]->%c\n", paths[i].name, paths[i].next[j]->weight, paths[i].next[j]->name);
        } else {
            printf("%c -[inf]-> no directed paths", paths[i].name);
        }
        printf("\n");
    }
}

Node newNode(int weight, char name) {
    Node new;
    new.weight = weight;
    new.name = name;
    new.nextsize = 0;
    new.next[0] = NULL;
    return new;
}

void main() {
    int size, i, j, tempWeight;
    char tempName;
    int *matrix;
    Node *paths;
    Node *traverser;
    printf("Enter node count: ");
    scanf("%d", &size);
    matrix = (int *)malloc(size*size*sizeof(int));
    paths = (Node *)malloc(size*sizeof(Node));

    printf("Enter name of Nodes:\n");
    //empty the paths
    for (i=0; i<size; i++) {
        paths[i].nextsize = 0;
        paths[i].next[0] = NULL;
        paths[i].weight = -1;
        printf("Node %d: ", i);
        scanf(" %c", &tempName);
        paths[i].name = tempName;
    }

    for (i = 0; i<size; i++) {
        for (j = 0; j<size; j++) {
            if (i==j) continue;
            else {
                printf("Weight from %c to %c: ", paths[i].name, paths[j].name);
                scanf("%d", &tempWeight);
                matrix[i*size+j] = tempWeight;
                if (tempWeight != 0) {
                    //path exists
                    Node* tempNode = (Node *)malloc(sizeof(Node));
                    tempNode->name = paths[j].name;
                    tempNode->weight = tempWeight;
                    tempNode->nextsize = 0;
                    tempNode->next[0] = NULL;
                    paths[i].next[paths[i].nextsize] = tempNode;
                    paths[i].nextsize +=1;
                } 
            }
        }
    }
    printPath(paths, size);
}