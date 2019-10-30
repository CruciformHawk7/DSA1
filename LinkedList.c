#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 400

struct Nd {
    int value;
    struct Nd *next;
};

typedef struct Nd * Node;

int size;
Node head;

void init       ();
void insertHead (int);
void insertTail (int);
void insertAfter(int, int);
int  deleteHead ();
int  deleteTail ();
int  delete     (int);
int  find       (int);
void print      ();
void dispHelp   ();
char prompt     ();

void init() {
    size = 0;
    head = NULL;
}

void insertHead(int val) {
    Node temp = (Node) malloc(sizeof(struct Nd));
    if ((temp==NULL) || (size==MAX_SIZE)) {
        printf("Overflow!\n");
        return;
    }
    temp->value = val;
    temp->next = head;
    head = temp;
    size++;
}

void insertTail(int val) {
    Node temp = (Node) malloc(sizeof(struct Nd));
    if ((temp==NULL) || (size==MAX_SIZE)) {
        printf("Overflow!\n");
        return;
    }
    Node iter = head;
    while (iter->next!=NULL)
        iter = iter->next;
    temp->value = val;
    iter->next = temp;
}

void insertAfter(int num, int val) {
    Node temp = (Node) malloc(sizeof(struct Nd));
    if ((temp==NULL) || (size==MAX_SIZE)) {
        printf("Overflow!\n");
        return;
    }
    Node iter = head;
    while (iter->next != NULL) {
        iter = iter->next;
        if (iter->value==num) break;
    }
    temp->value = val;
    temp->next = iter->next;
    iter->next = temp;
}

int deleteHead() {
    if (head==NULL) {
        printf("Underflow!\n");
        return -1;
    }
    int val = head->value;
    head = head->next;
    return val;
}

int deleteTail() {
    int val;
    Node iter = head;
    if (head==NULL) {
        printf("Underflow!\n");
        return -1;
    }
    while (iter->next->next!=NULL) 
        iter = iter->next;
    val = iter->next->value;
    iter->next = NULL;
    return val;

}

int delete(int num) {
    int val;
    if (head==NULL) {
        printf("Underflow!\n");
        return -1;
    }
    Node iter = head;
    while (iter->next!=NULL) {
        if (iter->value == num)
            break;
        iter = iter->next;
    }
    if (iter == NULL) {
        printf("Not found!\n");
        return -1;
    }
    if (iter->next == NULL) 
        return deleteTail();
    val = iter->value;
    iter->next = iter->next->next;
    return val;
}

int find(int num) {
    int pos = 0;
    if (head==NULL) {
        printf("Empty\n");
        return -1;
    }
    Node iter = head;
    while (iter->next!=NULL) {
        if (iter->value == num) return ++pos;
        iter = iter->next;
        pos++;
    }
    if (iter==NULL)  {
        printf("Does not exist: %d\n", num);
        return -1;
    }
}

void print() {
    if (head==NULL) {
        printf("Underflow!\n");
        return;
    }
    Node temp = head;
    while (temp!=NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

void dispHelp() {
    printf("1 Insert at head\n2 Insert at tail\n3 Insert at x\n");
    printf("4 Delete from head\n5 Delete from tail\n6 Delete x\n");
    printf("7 Find\n8 Display\n9 Exit\n0 Clear the list\n? Shows this list\n");
}

char prompt() {
    char choice;
    printf("> ");
    scanf(" %c", &choice);
    return choice;
}

int main() {
    char choice;
    int number, finder;
    dispHelp();
    init();
    do {
        choice = prompt();
        switch (choice) {
        case '1':
            printf("Enter the number: ");
            scanf("%d", &number);
            insertHead(number);
            break;
        case '2':
            printf("Enter the number: ");
            scanf("%d", &number);
            insertTail(number);
            break;
        case '3':
            printf("Enter the number: ");
            scanf("%d", &number);
            printf("Where to insert? ");
            scanf("%d", &finder);
            insertAfter(number, finder);
            break;
        case '4':
            number = deleteHead();
            if (number!=-1)
            printf("%d deleted\n", number);
            break;
        case '5':
            number = deleteTail();
            if (!number==-1)
            printf("%d deleted\n", number);
            break;
        case '6':
            printf("What to delete?");
            scanf("%d", &finder);
            number = delete(finder);
            printf("%d deleted\n", number);
            break;
        case '7':
            printf("Enter the number to find: ");
            scanf("%d", &finder);
            number = find(finder);
            if (number!=-1) printf("Number found at %d\n", number);
            else printf("Number not found\n");
            break;
        case '8':
            print();
            break;
        case '9':
            return 0;
            break;
        case '0':
            printf("Clearing.\n");
            init();
        case '?':
            dispHelp();
            break;
        default:
            printf("Not an option!\n");
        }
    } while (choice != '9');
    return 0;
}