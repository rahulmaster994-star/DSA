# VTU 3rd Semester Data Structures Laboratory (C Programming)

Implementation of fundamental Data Structures laboratory programs in C as per the VTU 3rd Semester Syllabus (BCS304 / 21CSL35 / 18CSL38).

---

## 📁 Repository Contents

| File | Description | Key Operations |
|------|-------------|----------------|
| [`01_singly_linked_list.c`](01_singly_linked_list.c) | **Singly Linked List (SLL)** implementation | `insertBeginning`, `insertEnd`, `insertPosition`, `insertAfterValue`, `deleteBeginning`, `deleteEnd`, `deletePosition`, `deleteValue`, `display`, `search` |
| [`02_stack_and_queue_using_linked_list.c`](02_stack_and_queue_using_linked_list.c) | **Stack & Queue using Singly Linked List** | **Stack (LIFO)**: `push`, `pop`, `peek`, `display`<br>**Queue (FIFO)**: `enqueue`, `dequeue`, `peek`, `display` |
| [`03_vtu_student_sll_stack_queue.c`](03_vtu_student_sll_stack_queue.c) | **VTU Student SLL (Stack & Queue Demo)** | Student records (USN, Name, Branch, Sem, Phone) demonstrating LIFO (Stack) and FIFO (Queue) |

---

## 🛠️ How to Compile and Run

### 1. Singly Linked List
```bash
gcc 01_singly_linked_list.c -o 01_singly_linked_list
./01_singly_linked_list
```

### 2. Stack and Queue using Linked List
```bash
gcc 02_stack_and_queue_using_linked_list.c -o 02_stack_and_queue_using_linked_list
./02_stack_and_queue_using_linked_list
```

### 3. VTU Student SLL Demonstration
```bash
gcc 03_vtu_student_sll_stack_queue.c -o 03_vtu_student_sll_stack_queue
./03_vtu_student_sll_stack_queue
```

---

## 📊 Sample Execution Outputs

### 1. Singly Linked List Execution Output
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

### 2. Stack Operations (LIFO) Output
```text
[SUCCESS] Pushed 10 onto the stack.
[SUCCESS] Pushed 20 onto the stack.
[SUCCESS] Pushed 30 onto the stack.

--- Stack Contents (Top to Bottom) ---
[30] <-- TOP
[20]
[10]
Total Elements in Stack: 3

Top element is: 30
[SUCCESS] Popped 30 from the stack.
```

### 3. Queue Operations (FIFO) Output
```text
[SUCCESS] Enqueued 100 into the queue.
[SUCCESS] Enqueued 200 into the queue.
[SUCCESS] Enqueued 300 into the queue.

--- Queue Contents (Front to Rear) ---
FRONT -> [100] -> [200] -> [300] <- REAR
Total Elements in Queue: 3

Front element is: 100
[SUCCESS] Dequeued 100 from the queue.
FRONT -> [200] -> [300] <- REAR
```
