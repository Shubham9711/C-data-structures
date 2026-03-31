# Data Structures & Algorithms

Personal practice repository for **data structures**, **algorithms**, and **recursion / dynamic programming** problems, mostly in **C++**.

## Contents

| Area | Location | Notes |
|------|----------|--------|
| **Binary trees** | [`Binary Tree/`](Binary%20Tree/) | Headers and sample code (`BTree.h`, `Binary_tree.cpp`) |
| **Graphs** | [`Graph/`](Graph/) | Graph implementations (`Graph.cpp`, `NewGraph.cpp`) |
| **Linked lists** | [`Linked List/`](Linked%20List/) | Singly, doubly, circular variants; `Linklist.h` |
| **Queues** | [`Queue/`](Queue/) | Array-based and linked-list implementations |
| **Stacks** | [`Stack/`](Stack/) | Array-based stack; `stackh.h` |
| **Trie** | [`TRIE.cpp`](TRIE.cpp) | Trie implementation (root) |
| **Searching & sorting** | [`Searching and sorting.h`](Searching%20and%20sorting.h) | Shared header utilities |
| **Recursion & DP** | [`zRecurrsion problems/`](zRecurrsion%20problems/) | Classic problems: subsets, knapsack, LCS, edit distance, Tower of Hanoi, grid paths, and more |

## Prerequisites

- A **C++** compiler (e.g. GCC, Clang, or MSVC).
- Some files are headers (`.h`); pair them with the corresponding `.cpp` sources when building.

## Building

There is no single build system yet. Compile individual sources as needed, for example:

```bash
g++ -std=c++17 -o program "Stack/stack_using_array.cpp"
```

Adjust paths and flags for your environment.

## License

This is a personal learning project; add a license if you plan to share it publicly.
