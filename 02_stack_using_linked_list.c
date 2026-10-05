#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Stack Implementation using LL */
struct Node *top = NULL;

/* Push Operation */
void push() {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = top;
    top = newNode;
    printf("%d pushed into stack.\n", newNode->data);
}

/* Pop Operation */
void pop() {
    struct Node *temp;
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;
    free(temp);
}

/* Peek Operation */
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

/* Display Operation */
void display() {
    struct Node *temp;
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    temp = top;
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

/* Main Function */
int main() {
    int choice;
    while (1) {
        printf("\n===== STACK USING LINKED LIST =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Program terminated.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
