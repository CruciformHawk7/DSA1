/*
 * A simple program to emulate Dijkstra's Algorithm
 * Using C
 */

#include<stdio.h>
#include<stdlib.h>

#define INFINITE_PATH -1

//#define SHOWDEBUGINFO

struct Node {
    int weight;
    char name;
    int location;
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
            printf("%c -[inf]-> no directed paths\n", paths[i].name);
        }
    }
}

int contains(char *arr, int size, char letter) {
    int i;
    for (i=0; i<size; i++) { if (arr[i]==letter) return 1; }
    return 0;
}

void aOnlyDijkstra(Node *paths, int size, int firstNode) {
    Node nextPath;    
    int nextNode, shortest, j, i;
    char *pathDefinition = (char *)malloc (sizeof(char)*size);
    shortest = paths[firstNode].next[0]->weight;
    nextPath = paths[firstNode];
    nextNode = 0;

    printf("\nShortest Path:\n%c", paths[firstNode].name);
    pathDefinition[0] = paths[firstNode].name;
    
    //find the shortest path at firstNode
    for (j = 0; j<size; j++) {
        for (i=0; i<nextPath.nextsize; i++) {
            if (nextPath.next[i]->weight<shortest && (!nextPath.next[i]->weight==0)) {
                shortest = nextPath.next[i]->weight;
                nextNode = i;
            }
        }
        if (contains(pathDefinition, j, nextPath.next[nextNode]->name)==1) break;
        pathDefinition[j+1] = nextPath.next[nextNode]->name;
        #ifdef SHOWDEBUGINFO 
            printf("\npathDefinition: %c\n", pathDefinition[j]);
        #endif
        printf("-[%d]->%c", nextPath.next[nextNode]->weight, nextPath.next[nextNode]->name);
        shortest = nextPath.next[0]->weight;
        if (shortest == INFINITE_PATH) break;
        #ifdef SHOWDEBUGINFO
            //printf("\nnextnode: %d\n", nextPath.next[nextNode]->location);
        #endif
        nextPath = paths[nextPath.next[nextNode]->location];
    }
    printf("\n");
}

int main() {
    int size, i, j, tempWeight;
    char tempName, choice, startNode, endNode;
    int *matrix;
    Node *paths;
    int firstNode = 0;
    printf("Enter node count: ");
    scanf("%d", &size);
    matrix = (int *)malloc(size*size*sizeof(int));
    paths = (Node *)malloc(size*sizeof(Node));
    char *pathDefinition;

    printf("Enter name of Nodes:\n");

    for (i=0; i<size; i++) {
        paths[i].nextsize = 0;
        paths[i].next[0] = NULL;
        paths[i].weight = INFINITE_PATH;
        paths[i].location = i;
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
                if (tempWeight != INFINITE_PATH) {
                    //path exists
                    Node* tempNode = (Node *)malloc(sizeof(Node));
                    tempNode->name = paths[j].name;
                    tempNode->weight = tempWeight;
                    tempNode->location = paths[j].location;
                    tempNode->nextsize = 0;
                    tempNode->next[0] = NULL;
                    paths[i].next[paths[i].nextsize] = tempNode;
                    paths[i].nextsize +=1;
                } 
            }
        }
    }

    while(1) {
        printf("\n\n1. Shortest possible path");
        printf("\n2. A -> B");
        printf("\n3. Show all paths");
        printf("\n*: Exit");
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        if (choice == '1') {
            printf("Enter first node: ");
            scanf(" %c", &startNode);
            //TODO compute firstNode
            for (i=0; i<size; i++) {
                if (paths[i].name == startNode) { firstNode = paths[i].location;
                printf("found: %c, %d", paths[i].name, paths[i].location); }
            }
            aOnlyDijkstra(paths, size, firstNode);
            
        } else if (choice == '2') {
            printf("Enter first node: ");
            scanf(" %c", &startNode);
            printf("Enter second node: ");
            scanf(" %c", &endNode);
        } else if (choice == '3') {
            printf("\n\nAll Paths:\n");
            printPath(paths, size);
        }
        else  {
            return 0;
        }
    }
}