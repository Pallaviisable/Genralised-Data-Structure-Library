# Generalised Data Structure Library (C++)

A generic, header-only C++ data structure library using templates.  
Each structure is split into a `.h` (declarations) and `.tpp` (template definitions) pair.

---

## Structures Included

| Structure | Files |
|---|---|
| Singly Linear Linked List | `SinglyLL.h` / `SinglyLL.tpp` |
| Singly Circular Linked List | `SinglyCLL.h` / `SinglyCLL.tpp` |
| Doubly Linear Linked List | `DoublyLL.h` / `DoublyLL.tpp` |
| Doubly Circular Linked List | `DoublyCLL.h` / `DoublyCLL.tpp` |
| Binary Search Tree | `BST.h` / `BST.tpp` |
| Queue (FIFO) | `Queue.h` / `Queue.tpp` |
| Stack (LIFO) | `Stack.h` / `Stack.tpp` |
| Array with Sorting | `ArrayX.h` / `ArrayX.tpp` |

---

## How to Compile & Run

```bash
g++ -std=c++17 main.cpp -o DSLibrary
./DSLibrary
```

---

## File Structure

```
DSLibrary/
├── SinglyLL.h / SinglyLL.tpp
├── SinglyCLL.h / SinglyCLL.tpp
├── DoublyLL.h / DoublyLL.tpp
├── DoublyCLL.h / DoublyCLL.tpp
├── BST.h / BST.tpp
├── Queue.h / Queue.tpp
├── Stack.h / Stack.tpp
├── ArrayX.h / ArrayX.tpp
├── main.cpp
└── README.md
```

> **Note on `.tpp` files:** C++ templates must be visible to the compiler at the point of use.  
> Each `.h` file `#include`s its own `.tpp` at the bottom — do **not** compile `.tpp` files separately.

---

## Sorting Algorithms (ArrayX)

- `bubbleSort()` — standard, prints each pass
- `bubbleSortEfficient()` — with early-exit flag
- `bubbleSortEfficientX(INC_ORDER / DEC_ORDER)` — direction control + early exit
- `SelectionSort()` — ascending
- `InsertionSort()` — ascending

---

## Author

**Pallavi Sable** — 06/01/2026
