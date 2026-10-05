/*
 * -----------------------------------------------------------------------------
 * VISVESVARAYA TECHNOLOGICAL UNIVERSITY (VTU)
 * 3rd Semester B.E. / B.Tech Computer Science & Engineering / Allied Branches
 * Course: Data Structures and Applications Laboratory (BCS304 / 21CSL35 / 18CSL38)
 *
 * Program: Singly Linked List (SLL) of Student Data
 * Problem Statement:
 *   Develop a menu driven Program in C for the following operations on
 *   Singly Linked List (SLL) of Student Data with the fields:
 *   USN, Name, Programme/Branch, Sem, Phone Number:
 *     a. Create a SLL of N Students Data by using front insertion.
 *     b. Display the status of SLL and count the number of nodes in it.
 *     c. Perform Insertion and Deletion at End of SLL.
 *     d. Perform Insertion and Deletion at Front of SLL.
 *     e. Demonstrate how this SLL can be used as STACK (LIFO) and QUEUE (FIFO).
 *     f. Exit.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of Student Node
struct StudentNode {
    char usn[20];
    char name[50];
    char branch[30];
    int sem;
    char phone[15];
    struct StudentNode *next;
};

typedef struct StudentNode* StudentPtr;

// Function Prototypes
StudentPtr createStudentNode();
StudentPtr insertFront(StudentPtr head);
StudentPtr insertEnd(StudentPtr head);
StudentPtr deleteFront(StudentPtr head);
StudentPtr deleteEnd(StudentPtr head);
void display(StudentPtr head);
int countNodes(StudentPtr head);
StudentPtr createListN(StudentPtr head);
void freeAll(StudentPtr head);

// Allocate and read student details from user
StudentPtr createStudentNode() {
    StudentPtr newNode = (StudentPtr)malloc(sizeof(struct StudentNode));
    if (newNode == NULL) {
        printf("\n[ERROR] Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter Student Details:\n");
    printf("  USN           : ");
    scanf("%19s", newNode->usn);
    printf("  Name          : ");
    scanf("%49s", newNode->name);
    printf("  Programme/Dept: ");
    scanf("%29s", newNode->branch);
    printf("  Semester      : ");
    scanf("%d", &newNode->sem);
    printf("  Phone No      : ");
    scanf("%14s", newNode->phone);

    newNode->next = NULL;
    return newNode;
}

// a. Create SLL of N students using front insertion
StudentPtr createListN(StudentPtr head) {
    int n;
    printf("\nEnter number of students (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("[WARNING] Invalid count N.\n");
        return head;
    }
    for (int i = 1; i <= n; i++) {
        printf("\n--- Student %d of %d ---", i, n);
        head = insertFront(head);
    }
    return head;
}

// Front Insertion (used also as Stack PUSH)
StudentPtr insertFront(StudentPtr head) {
    StudentPtr newNode = createStudentNode();
    newNode->next = head;
    printf("\n[SUCCESS] Inserted student (%s) at Front.\n", newNode->usn);
    return newNode;
}

// End Insertion (used also as Queue ENQUEUE)
StudentPtr insertEnd(StudentPtr head) {
    StudentPtr newNode = createStudentNode();
    if (head == NULL) {
        printf("\n[SUCCESS] Inserted student (%s) as the first node.\n", newNode->usn);
        return newNode;
    }
    StudentPtr temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("\n[SUCCESS] Inserted student (%s) at End.\n", newNode->usn);
    return head;
}

// Front Deletion (used as Stack POP and Queue DEQUEUE)
StudentPtr deleteFront(StudentPtr head) {
    if (head == NULL) {
        printf("\n[UNDERFLOW] List is empty! Nothing to delete.\n");
        return NULL;
    }
    StudentPtr temp = head;
    head = head->next;
    printf("\n[SUCCESS] Deleted student from Front: USN = %s, Name = %s\n", temp->usn, temp->name);
    free(temp);
    return head;
}

// End Deletion
StudentPtr deleteEnd(StudentPtr head) {
    if (head == NULL) {
        printf("\n[UNDERFLOW] List is empty! Nothing to delete.\n");
        return NULL;
    }
    if (head->next == NULL) {
        printf("\n[SUCCESS] Deleted single student: USN = %s, Name = %s\n", head->usn, head->name);
        free(head);
        return NULL;
    }
    StudentPtr prev = NULL;
    StudentPtr curr = head;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    printf("\n[SUCCESS] Deleted student from End: USN = %s, Name = %s\n", curr->usn, curr->name);
    free(curr);
    return head;
}

// Count total nodes
int countNodes(StudentPtr head) {
    int count = 0;
    StudentPtr temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Display SLL status and formatted student table
void display(StudentPtr head) {
    if (head == NULL) {
        printf("\n[STATUS] Singly Linked List is EMPTY (0 nodes).\n");
        return;
    }

    printf("\n========================================================================================\n");
    printf("                                STUDENT DATABASE STATUS                                 \n");
    printf("========================================================================================\n");
    printf("%-15s %-25s %-15s %-8s %-15s\n", "USN", "NAME", "PROGRAMME", "SEM", "PHONE");
    printf("----------------------------------------------------------------------------------------\n");

    StudentPtr temp = head;
    while (temp != NULL) {
        printf("%-15s %-25s %-15s %-8d %-15s\n",
               temp->usn, temp->name, temp->branch, temp->sem, temp->phone);
        temp = temp->next;
    }
    printf("========================================================================================\n");
    printf("Total Students in SLL: %d\n", countNodes(head));
}

// Free entire list
void freeAll(StudentPtr head) {
    StudentPtr temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Demonstration explanation for VTU Viva / Lab evaluation
void demonstrateStackQueue() {
    printf("\n====================================================================\n");
    printf("         HOW SLL DEMONSTRATES STACK (LIFO) AND QUEUE (FIFO)         \n");
    printf("====================================================================\n");
    printf(" 1. STACK DEMONSTRATION (LIFO - Last In First Out):\n");
    printf("    - PUSH Operation  : Performed by 'Insert at Front'.\n");
    printf("    - POP Operation   : Performed by 'Delete from Front'.\n");
    printf("    Both operations occur at the same end (head of SLL) in O(1) time.\n\n");
    printf(" 2. QUEUE DEMONSTRATION (FIFO - First In First Out):\n");
    printf("    - ENQUEUE Operation: Performed by 'Insert at End'.\n");
    printf("    - DEQUEUE Operation: Performed by 'Delete from Front'.\n");
    printf("    Insert at rear and delete from front ensures FIFO ordering.\n");
    printf("====================================================================\n");
}

int main() {
    StudentPtr head = NULL;
    int choice;

    printf("=======================================================================\n");
    printf("   VTU 3RD SEM LAB (BCS304 / 21CSL35): STUDENT SINGLY LINKED LIST     \n");
    printf("=======================================================================\n");

    while (1) {
        printf("\n-------------------------- MAIN MENU --------------------------\n");
        printf(" 1. Create SLL of N Students (using Front Insertion)\n");
        printf(" 2. Display SLL Status and Count Nodes\n");
        printf(" 3. Insert Student at End (Queue Enqueue demonstration)\n");
        printf(" 4. Delete Student from End\n");
        printf(" 5. Insert Student at Front (Stack Push demonstration)\n");
        printf(" 6. Delete Student from Front (Stack Pop / Queue Dequeue demo)\n");
        printf(" 7. Demonstration of SLL as Stack and Queue (Theory/Summary)\n");
        printf(" 8. Exit\n");
        printf("----------------------------------------------------------------\n");
        printf("Enter your choice (1-8): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                head = createListN(head);
                display(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = insertEnd(head);
                display(head);
                break;
            case 4:
                head = deleteEnd(head);
                display(head);
                break;
            case 5:
                head = insertFront(head);
                display(head);
                break;
            case 6:
                head = deleteFront(head);
                display(head);
                break;
            case 7:
                demonstrateStackQueue();
                break;
            case 8:
                printf("\nExiting program and releasing dynamic memory. Thank you!\n");
                freeAll(head);
                return 0;
            default:
                printf("\n[ERROR] Invalid choice! Please select between 1 and 8.\n");
        }
    }

    freeAll(head);
    return 0;
}
