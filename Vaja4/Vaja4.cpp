// BINARY SEARCH TREE

#include <iostream>
using namespace std;

struct Node {
    int key = 0;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
};


// Helper function to display the menu
void displayMenu() {
    cout << "\nBinary Search Tree - Options:\n";
    cout << "1) Insert a value\n";
    cout << "2) Print sorted values\n";
    cout << "3) Print connections\n";
    cout << "4) Search for a value\n";
    cout << "5) Find minimum and maximum\n";
    cout << "6) Find predecessor and successor\n";
    cout << "7) Delete a value\n";
    cout << "8) Exit\n";
    cout << "\nChoose: ";
}

// Insert a value into the BST
void insert(int value, Node*& root) {
    Node* parent = nullptr;
    Node* current = root;

    // Find the parent node for the new value
    while (current != nullptr) {
        parent = current;
        if (value < current->key) {
            current = current->left;
        }
        else if (value > current->key) {
            current = current->right;
        }
        else {
            cout << "ERROR: Duplicate value not allowed.\n";
            return;
        }
    }

    // Create a new node
    Node* newNode = new Node{ value, parent, nullptr, nullptr };

    if (parent == nullptr) {
        root = newNode; // The tree was empty, new node becomes the root
    }
    else if (value < parent->key) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }
}

// Search for a value in the BST
Node* search(int value, Node* root) {
    Node* current = root;
    while (current != nullptr && current->key != value) {
        current = (value < current->key) ? current->left : current->right;
    }
    return current;
}

// Print the tree in sorted order (in-order traversal)
void printSorted(Node* node) {
    if (node != nullptr) {
        printSorted(node->left);
        cout << node->key << " ";
        printSorted(node->right);
    }
}

// Print the connections of the BST nodes
void printConnections(Node* node) {
    if (node == nullptr) return;

    if (node->left != nullptr) {
        cout << node->key << " -> " << node->left->key << endl;
        printConnections(node->left);
    }

    if (node->right != nullptr) {
        cout << node->key << " -> " << node->right->key << endl;
        printConnections(node->right);
    }
}

// Find the minimum value in the BST
Node* findMinimum(Node* root) {
    Node* current = root;
    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Find the maximum value in the BST
Node* findMaximum(Node* root) {
    Node* current = root;
    while (current != nullptr && current->right != nullptr) {
        current = current->right;
    }
    return current;
}

// Find the predecessor of a given node
Node* findPredecessor(Node* node) {
    if (node->left != nullptr) {
        return findMaximum(node->left);
    }

    Node* parent = node->parent;
    while (parent != nullptr && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

// Find the successor of a given node
Node* findSuccessor(Node* node) {
    if (node->right != nullptr) {
        return findMinimum(node->right);
    }

    Node* parent = node->parent;
    while (parent != nullptr && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

// Handle deletion for nodes with 0 or 1 child
void deleteCase1Or2(Node*& target, Node*& root) {
    Node* child = (target->left != nullptr) ? target->left : target->right;

    if (child != nullptr) {
        child->parent = target->parent;
    }

    if (target->parent == nullptr) {
        root = child;
    }
    else if (target == target->parent->left) {
        target->parent->left = child;
    }
    else {
        target->parent->right = child;
    }

    delete target;
}

// Delete a node from the BST
void deleteNode(Node*& target, Node*& root) {
    if (target->left == nullptr || target->right == nullptr) {
        deleteCase1Or2(target, root);
    }
    else {
        Node* successor = findSuccessor(target);
        target->key = successor->key;
        deleteCase1Or2(successor, root);
    }
}

int main() {
    Node* root = nullptr;
    bool running = true;

    while (running) {
        displayMenu();
        int choice, value;
        cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(value, root);
            break;

        case 2:
            if (root == nullptr) {
                cout << "Tree is empty.\n";
            }
            else {
                printSorted(root);
                cout << endl;
            }
            break;

        case 3:
            if (root == nullptr) {
                cout << "Tree is empty.\n";
            }
            else {
                printConnections(root);
            }
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(value, root) != nullptr) {
                cout << "Value found in the tree.\n";
            }
            else {
                cout << "Value not found.\n";
            }
            break;

        case 5:
            if (root == nullptr) {
                cout << "Tree is empty.\n";
            }
            else {
                Node* minNode = findMinimum(root);
                Node* maxNode = findMaximum(root);
                cout << "Minimum value: " << minNode->key << endl;
                cout << "Maximum value: " << maxNode->key << endl;
            }
            break;

        case 6:
            cout << "Enter value to find predecessor and successor: ";
            cin >> value;
            Node* target;
            target = search(value, root);

            if (target == nullptr) {
                cout << "Value not found.\n";
            }
            else {
                Node* predecessor = findPredecessor(target);
                Node* successor = findSuccessor(target);

                if (predecessor != nullptr) {
                    cout << "Predecessor: " << predecessor->key << endl;
                }
                else {
                    cout << "No predecessor exists.\n";
                }

                if (successor != nullptr) {
                    cout << "Successor: " << successor->key << endl;
                }
                else {
                    cout << "No successor exists.\n";
                }
            }
            break;

        case 7:
            cout << "Enter value to delete: ";
            cin >> value;
            Node* nodeToDelete;
            nodeToDelete = search(value, root);
            if (nodeToDelete == nullptr) {
                cout << "Value not found.\n";
            }
            else {
                deleteNode(nodeToDelete, root);
                cout << "Value deleted.\n";
            }
            break;

        case 8:
            running = false;
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    }

    return 0;
}
