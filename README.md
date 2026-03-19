# Generalised Data Structure Library (C++)

> A from-scratch, production-structured C++ library implementing core data structures and sorting algorithms using **generic templates** — designed to work with any data type out of the box.

This project demonstrates a strong foundation in **Object-Oriented Programming**, **memory management**, **C++ templates**, and **algorithm design** — all implemented without relying on the STL.

---

## Why This Project

Most developers use `std::list`, `std::stack`, or `std::queue` without understanding what happens under the hood. This library builds each of those structures from the ground up — every node, every pointer link, every edge case handled manually. The goal was to deeply understand how data structures work at the memory level, not just how to use them.

---

## What's Inside

### Data Structures

| Structure | Files | Key Operations |
|---|---|---|
| Singly Linear Linked List | `SinglyLL.h/.tpp` | InsertFirst, InsertLast, InsertAtPos, DeleteFirst, DeleteLast, DeleteAtPos, Display, Count |
| Singly Circular Linked List | `SinglyCLL.h/.tpp` | Same as above — circular `last→first` link maintained on every operation |
| Doubly Linear Linked List | `DoublyLL.h/.tpp` | Bidirectional traversal with `prev` and `next` pointers |
| Doubly Circular Linked List | `DoublyCLL.h/.tpp` | Full circular bidirectional links — both `first→prev` and `last→next` maintained |
| Binary Search Tree | `BST.h/.tpp` | Insert, Inorder/Preorder/Postorder traversal, Search, CountNodes, CountParents, CountLeafs |
| Queue (FIFO) | `Queue.h/.tpp` | enqueue, dequeue, Display, Count |
| Stack (LIFO) | `Stack.h/.tpp` | push, pop, peep, Display, Count |
| Array with Sorting | `ArrayX.h/.tpp` | Accept, Display, CheckSorted + 5 sort variants |

### Sorting Algorithms (ArrayX)

| Algorithm | Variant | Notes |
|---|---|---|
| Bubble Sort | `bubbleSort()` | Standard — prints state after every pass |
| Bubble Sort | `bubbleSortEfficient()` | Early-exit flag — stops when no swaps occur |
| Bubble Sort | `bubbleSortEfficientX(option)` | Ascending **or** descending, with early exit |
| Selection Sort | `SelectionSort()` | Finds minimum each pass, O(n²) comparisons |
| Insertion Sort | `InsertionSort()` | Stable sort, efficient on nearly-sorted data |

---

## Technical Highlights

- **100% generic using C++ templates** — every class works with `int`, `float`, `char`, `string`, or any custom type
- **Proper separation of concerns** — declarations in `.h`, definitions in `.tpp`, driver in `main.cpp` (industry-standard layout for template libraries)
- **Manual memory management** — explicit `new` and `delete` with no memory leaks; every deletion re-links surrounding nodes correctly before freeing
- **Edge case handling** — all operations correctly handle empty lists, single-node lists, and invalid positions
- **Circular link integrity** — both `SinglyCLL` and `DOUBLYCLL` maintain circular links on every insert and delete, not just at the end
- **BST with recursive helpers** — private overloaded methods keep the public API clean while allowing full recursive tree traversal
- **`#pragma once` guards** — prevents double-inclusion across large projects
- **Consistent function header documentation** — every method is documented with input, output, and description

---

## How to Compile & Run

```bash
g++ -std=c++17 main.cpp -o DSLibrary
./DSLibrary
```

No external dependencies. No STL data structures used.

---

## File Structure

```
DSLibrary/
├── SinglyLL.h      ← Class & node declarations
├── SinglyLL.tpp    ← Template method definitions
├── SinglyCLL.h / SinglyCLL.tpp
├── DoublyLL.h  / DoublyLL.tpp
├── DoublyCLL.h / DoublyCLL.tpp
├── BST.h       / BST.tpp
├── Queue.h     / Queue.tpp
├── Stack.h     / Stack.tpp
├── ArrayX.h    / ArrayX.tpp
├── main.cpp        ← Demo driver for all structures
└── README.md
```

> **Note on `.tpp` files:** C++ templates require their full definition to be visible to the compiler at the point of instantiation. Each `.h` includes its own `.tpp` at the bottom. Never compile `.tpp` files directly — only compile `main.cpp`.

---

## Skills Demonstrated

`C++` &nbsp;|&nbsp; `OOP` &nbsp;|&nbsp; `Templates & Generics` &nbsp;|&nbsp; `Pointers & Manual Memory Management` &nbsp;|&nbsp; `Linked Lists` &nbsp;|&nbsp; `Trees` &nbsp;|&nbsp; `Sorting Algorithms` &nbsp;|&nbsp; `Data Structures` &nbsp;|&nbsp; `Header-only Library Design`

---

## Author

**Pallavi Sable** — 06/01/2026
