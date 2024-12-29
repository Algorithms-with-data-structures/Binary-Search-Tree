# Binary Search Tree (BST) Implementation

This repository contains a C++ implementation of a **Binary Search Tree (BST)**. It provides functionality to insert, search, and delete nodes, as well as operations to print sorted values, find the minimum and maximum values, and determine predecessor and successor nodes.

---

## About Binary Search Trees

A Binary Search Tree (BST) is a data structure in which each node has at most two children, referred to as the left and right child. The key properties of a BST are:

- **Left Subtree Property:** All keys in the left subtree of a node are smaller than the node's key.
- **Right Subtree Property:** All keys in the right subtree of a node are greater than the node's key.

### Advantages
- Efficient searching, insertion, and deletion operations (average time complexity: **O(log n)**).
- In-order traversal produces sorted data.

### Common Use Cases
- Databases and search engines.
- Maintaining sorted data.
- Implementing associative arrays and sets.

---

## Features

This program implements the following BST operations:

1. **Insert a Value**: Add a new value to the BST while maintaining the BST properties.
2. **Print Sorted Values**: Display the elements in ascending order using in-order traversal.
3. **Print Connections**: Show parent-child relationships in the BST.
4. **Search for a Value**: Locate a specific value in the BST.
5. **Find Minimum and Maximum**: Retrieve the smallest and largest values in the BST.
6. **Find Predecessor and Successor**: Determine the predecessor and successor of a given value.
7. **Delete a Value**: Remove a node from the BST while preserving its properties.
8. **Exit**: Exit the program.

---

## How to Use

### Prerequisites

To run this program, you need:
- A C++ compiler (e.g., GCC, Clang, or MSVC).
- A terminal or IDE to execute the compiled program.

### Compilation and Execution

1. Clone the repository or copy the source code into a file named `bst.cpp`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using the following command:

   ```bash
   g++ bst.cpp -o bst
   ```

4. Run the program:

   ```bash
   ./bst
   ```

### Menu Options

The program presents a menu-driven interface. You can interact with it by choosing one of the following options:

1. **Insert a Value**: Enter the value to add to the BST.
2. **Print Sorted Values**: Displays all values in ascending order.
3. **Print Connections**: Shows parent-child relationships in the tree.
4. **Search for a Value**: Enter a value to search for its existence in the tree.
5. **Find Minimum and Maximum**: Displays the smallest and largest values.
6. **Find Predecessor and Successor**: Provides the predecessor and successor of a given value.
7. **Delete a Value**: Removes a specified value from the BST.
8. **Exit**: Exits the program.

---

## Code Overview

### Key Components

- **Node Structure**: Represents each node of the BST with attributes for `key`, `parent`, `left`, and `right`.
- **Insert Function**: Adds new nodes while maintaining the BST properties.
- **Search Function**: Locates a node with the specified value.
- **Traversal Functions**: Includes in-order traversal to print sorted values.
- **Delete Function**: Removes a node from the BST and adjusts the tree structure.

### Example Usage

#### Insert Values
```
Enter value to insert: 50
Enter value to insert: 30
Enter value to insert: 70
```

#### Print Sorted Values
```
30 50 70
```

#### Find Minimum and Maximum
```
Minimum value: 30
Maximum value: 70
```

#### Delete a Value
```
Enter value to delete: 30
Value deleted.
```

---

## Additional Notes

- **Duplicate Values**: This implementation does not allow duplicate values in the BST.
- **Empty Tree Handling**: All operations handle cases where the tree is empty.

