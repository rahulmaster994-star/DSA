#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insertBeginning(struct Node *head, int value) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode;
    struct Node *temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* insertPosition(struct Node *head, int value, int position) {
    struct Node *newNode;
    struct Node *temp;
    int i;

    if (position == 1)
        return insertBeginning(head, value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    temp = head;
    for (i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            free(newNode);
            return head;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertAfterValue(struct Node *head, int key, int value) {
    struct Node *temp;
    struct Node *newNode;

    temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }

    printf("Value not found\n");
    return head;
}

struct Node* deleteBeginning(struct Node *head) {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteEnd(struct Node *head) {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deletePosition(struct Node *head, int position) {
    struct Node *temp;
    struct Node *deleteNode;
    int i;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (position == 1)
        return deleteBeginning(head);

    temp = head;
    for (i = 1; i < position - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position\n");
        return head;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
    return head;
}

struct Node* deleteValue(struct Node *head, int value) {
    struct Node *temp;
    struct Node *deleteNode;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (head->data == value)
        return deleteBeginning(head);

    temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == value) {
            deleteNode = temp->next;
            temp->next = deleteNode->next;
            free(deleteNode);
            return head;
        }
        temp = temp->next;
    }

    printf("Value not found\n");
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("HEAD -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(struct Node *head, int value) {
    int position = 1;

    while (head != NULL) {
        if (head->data == value) {
            printf("Value found at position %d\n", position);
            return;
        }
        head = head->next;
        position++;
    }

    printf("Value not found\n");
}

int main() {
    struct Node *head = NULL;

    head = insertBeginning(head, 20);
    head = insertBeginning(head, 10);

    head = insertEnd(head, 40);

    head = insertPosition(head, 30, 3);

    head = insertAfterValue(head, 30, 35);

    printf("Linked List:\n");
    display(head);

    head = deleteBeginning(head);
    printf("\nAfter deleting beginning:\n");
    display(head);

    head = deleteEnd(head);
    printf("\nAfter deleting end:\n");
    display(head);

    head = deletePosition(head, 2);
    printf("\nAfter deleting position 2:\n");
    display(head);

    head = deleteValue(head, 30);
    printf("\nAfter deleting value 30:\n");
    display(head);

    printf("\nSearching 20:\n");
    search(head, 20);

    return 0;
}
