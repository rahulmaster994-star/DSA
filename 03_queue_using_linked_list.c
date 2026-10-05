#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Queue Implementation using LL */
struct Node *front = NULL;
struct Node *rear = NULL;

/* Enqueue Operation */
void enqueue() {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued into queue.\n", newNode->data);
}

/* Dequeue Operation */
void dequeue() {
    struct Node *temp;
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    temp = front;
    printf("%d dequeued from queue.\n", front->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

/* Peek Operation */
void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

/* Display Operation */
void display() {
    struct Node *temp;
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    temp = front;
    printf("Queue elements (Front to Rear):\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Main Function */
int main() {
    int choice;
    while (1) {
        printf("\n===== QUEUE USING LINKED LIST =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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
