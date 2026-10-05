# VTU 3rd Semester Data Structures Laboratory (C Programming)

Implementation of fundamental Data Structures laboratory programs in C as per the VTU 3rd Semester Syllabus (BCS304 / 21CSL35 / 18CSL38).

---

## 📁 Repository Contents

| File | Description | Key Operations |
|------|-------------|----------------|
| [`01_singly_linked_list.c`](01_singly_linked_list.c) | **Singly Linked List (SLL)** | `insertBeginning`, `insertEnd`, `insertPosition`, `insertAfterValue`, `deleteBeginning`, `deleteEnd`, `deletePosition`, `deleteValue`, `display`, `search` |
| [`02_stack_using_linked_list.c`](02_stack_using_linked_list.c) | **Stack using Linked List (LIFO)** | `push()`, `pop()`, `peek()`, `display()` |
| [`03_queue_using_linked_list.c`](03_queue_using_linked_list.c) | **Queue using Linked List (FIFO)** | `enqueue()`, `dequeue()`, `peek()`, `display()` |
| [`02_stack_and_queue_using_linked_list.c`](02_stack_and_queue_using_linked_list.c) | **Combined Stack & Queue (SLL)** | Unified menu for both Stack & Queue via SLL |
| [`03_vtu_student_sll_stack_queue.c`](03_vtu_student_sll_stack_queue.c) | **VTU Student SLL Demonstration** | Student records (USN, Name, Branch, Sem, Phone) demonstrating LIFO (Stack) and FIFO (Queue) |

---

## 🛠️ How to Compile and Run

### 1. Singly Linked List
```bash
gcc 01_singly_linked_list.c -o 01_singly_linked_list
./01_singly_linked_list
```

### 2. Stack using Linked List
```bash
gcc 02_stack_using_linked_list.c -o 02_stack_using_linked_list
./02_stack_using_linked_list
```

### 3. Queue using Linked List
```bash
gcc 03_queue_using_linked_list.c -o 03_queue_using_linked_list
./03_queue_using_linked_list
```

---

## 📊 Sample Execution Outputs

### 1. Singly Linked List
```text
Linked List:
HEAD -> 10 -> 20 -> 30 -> 35 -> 40 -> NULL

After deleting beginning:
HEAD -> 20 -> 30 -> 35 -> 40 -> NULL

After deleting end:
HEAD -> 20 -> 30 -> 35 -> NULL

After deleting position 2:
HEAD -> 20 -> 35 -> NULL
Value not found

After deleting value 30:
HEAD -> 20 -> 35 -> NULL

Searching 20:
Value found at position 1
```

### 2. Stack using Linked List (LIFO)
```text
===== STACK USING LINKED LIST =====
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter value: 10
10 pushed into stack.

Enter your choice: 1
Enter value: 20
20 pushed into stack.

Enter your choice: 4
Stack elements:
20
10

Enter your choice: 3
Top element: 20

Enter your choice: 2
20 popped from stack.
```

### 3. Queue using Linked List (FIFO)
```text
===== QUEUE USING LINKED LIST =====
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter value: 100
100 enqueued into queue.

Enter your choice: 1
Enter value: 200
200 enqueued into queue.

Enter your choice: 4
Queue elements (Front to Rear):
100 200

Enter your choice: 3
Front element: 100

Enter your choice: 2
100 dequeued from queue.
```
