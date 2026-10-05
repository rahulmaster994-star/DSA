/*
 * -----------------------------------------------------------------------------
 * VTU 3rd Semester Data Structures Laboratory
 * Program: Implementation of Stack and Queue using Linked List
 * Description: Demonstrates how a Singly Linked List can be used to implement:
 *              Part A: Stack (LIFO - Last In First Out)
 *                      - Push (Insert at Front)
 *                      - Pop (Delete from Front)
 *                      - Peek (Top element)
 *                      - Display Stack
 *              Part B: Queue (FIFO - First In First Out)
 *                      - Enqueue (Insert at Rear)
 *                      - Dequeue (Delete from Front)
 *                      - Peek (Front element)
 *                      - Display Queue
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

// Node definition for Linked List
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node* NodePtr;

// Helper function to create a new node
NodePtr createNode(int value) {
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\n[OVERFLOW] Heap memory full! Cannot allocate node.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* ========================================================================= */
/*                          STACK IMPLEMENTATION                             */
/* ========================================================================= */

typedef struct {
    NodePtr top;
    int size;
} Stack;

void initStack(Stack *s) {
    s->top = NULL;
    s->size = 0;
}

int isStackEmpty(Stack *s) {
    return (s->top == NULL);
}

void push(Stack *s, int value) {
    NodePtr newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    printf("\n[SUCCESS] Pushed %d onto the stack.\n", value);
}

int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("\n[UNDERFLOW] Stack is empty! Cannot pop.\n");
        return -1;
    }
    NodePtr temp = s->top;
    int poppedVal = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    printf("\n[SUCCESS] Popped %d from the stack.\n", poppedVal);
    return poppedVal;
}

int peekStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("\n[INFO] Stack is empty.\n");
        return -1;
    }
    return s->top->data;
}

void displayStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("\n[STATUS] Stack is empty: [TOP -> NULL]\n");
        return;
    }
    printf("\n--- Stack Contents (Top to Bottom) ---\n");
    NodePtr temp = s->top;
    while (temp != NULL) {
        if (temp == s->top) {
            printf("[%d] <-- TOP\n", temp->data);
        } else {
            printf("[%d]\n", temp->data);
        }
        temp = temp->next;
    }
    printf("Total Elements in Stack: %d\n", s->size);
}

void clearStack(Stack *s) {
    while (!isStackEmpty(s)) {
        pop(s);
    }
}

/* ========================================================================= */
/*                          QUEUE IMPLEMENTATION                             */
/* ========================================================================= */

typedef struct {
    NodePtr front;
    NodePtr rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int isQueueEmpty(Queue *q) {
    return (q->front == NULL);
}

void enqueue(Queue *q, int value) {
    NodePtr newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    printf("\n[SUCCESS] Enqueued %d into the queue.\n", value);
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("\n[UNDERFLOW] Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    NodePtr temp = q->front;
    int dequeuedVal = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    printf("\n[SUCCESS] Dequeued %d from the queue.\n", dequeuedVal);
    return dequeuedVal;
}

int peekQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("\n[INFO] Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("\n[STATUS] Queue is empty: [FRONT -> NULL <- REAR]\n");
        return;
    }
    printf("\n--- Queue Contents (Front to Rear) ---\n");
    printf("FRONT -> ");
    NodePtr temp = q->front;
    while (temp != NULL) {
        printf("[%d] ", temp->data);
        if (temp->next != NULL) {
            printf("-> ");
        }
        temp = temp->next;
    }
    printf("<- REAR\n");
    printf("Total Elements in Queue: %d\n", q->size);
}

void clearQueue(Queue *q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
}

/* ========================================================================= */
/*                               SUB MENUS                                   */
/* ========================================================================= */

void runStackMenu(Stack *s) {
    int choice, val;
    while (1) {
        printf("\n====== STACK OPERATIONS (LIFO) ======\n");
        printf(" 1. Push\n");
        printf(" 2. Pop\n");
        printf(" 3. Peek (Top element)\n");
        printf(" 4. Display Stack\n");
        printf(" 5. Back to Main Menu\n");
        printf("=====================================\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(s, val);
                displayStack(s);
                break;
            case 2:
                pop(s);
                displayStack(s);
                break;
            case 3:
                val = peekStack(s);
                if (val != -1) {
                    printf("\nTop element is: %d\n", val);
                }
                break;
            case 4:
                displayStack(s);
                break;
            case 5:
                return;
            default:
                printf("\n[ERROR] Invalid choice!\n");
        }
    }
}

void runQueueMenu(Queue *q) {
    int choice, val;
    while (1) {
        printf("\n====== QUEUE OPERATIONS (FIFO) ======\n");
        printf(" 1. Enqueue (Insert Rear)\n");
        printf(" 2. Dequeue (Delete Front)\n");
        printf(" 3. Peek (Front element)\n");
        printf(" 4. Display Queue\n");
        printf(" 5. Back to Main Menu\n");
        printf("=====================================\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(q, val);
                displayQueue(q);
                break;
            case 2:
                dequeue(q);
                displayQueue(q);
                break;
            case 3:
                val = peekQueue(q);
                if (val != -1) {
                    printf("\nFront element is: %d\n", val);
                }
                break;
            case 4:
                displayQueue(q);
                break;
            case 5:
                return;
            default:
                printf("\n[ERROR] Invalid choice!\n");
        }
    }
}

/* ========================================================================= */
/*                              MAIN FUNCTION                                */
/* ========================================================================= */

int main() {
    Stack s;
    Queue q;
    initStack(&s);
    initQueue(&q);

    int mainChoice;

    printf("=================================================================\n");
    printf("   VTU 3RD SEM DSA LAB: STACK & QUEUE USING LINKED LIST          \n");
    printf("=================================================================\n");

    while (1) {
        printf("\n============== MAIN MENU ==============\n");
        printf(" 1. Stack Operations (LIFO using SLL)\n");
        printf(" 2. Queue Operations (FIFO using SLL)\n");
        printf(" 3. Exit\n");
        printf("=======================================\n");
        printf("Enter your choice (1-3): ");

        if (scanf("%d", &mainChoice) != 1) {
            printf("\nInvalid input! Exiting.\n");
            break;
        }

        switch (mainChoice) {
            case 1:
                runStackMenu(&s);
                break;
            case 2:
                runQueueMenu(&q);
                break;
            case 3:
                printf("\nFreeing memory and exiting... Goodbye!\n");
                clearStack(&s);
                clearQueue(&q);
                return 0;
            default:
                printf("\n[ERROR] Invalid choice! Select 1, 2, or 3.\n");
        }
    }

    clearStack(&s);
    clearQueue(&q);
    return 0;
}
