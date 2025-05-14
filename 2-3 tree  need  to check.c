#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key1;
    int key2;
    struct Node* left;
    struct Node* middle;
    struct Node* right;
};

struct Tree {
    struct Node* root;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key1 = key;
    newNode->key2 = -1; // Initialize to -1 indicating the node has only one key
    newNode->left = NULL;
    newNode->middle = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Tree* createTree() {
    struct Tree* newTree = (struct Tree*)malloc(sizeof(struct Tree));
    newTree->root = NULL;
    return newTree;
}

void splitNode(struct Node* parent, struct Node* child, int key, struct Node* newChild) {
    struct Node* newNode = createNode(key);

    if (key < parent->key1) {
        newNode->left = newChild;
        newNode->middle = parent->middle;
        parent->middle = parent->left;
        parent->left = child;
    } else if (key > parent->key2) {
        newNode->left = parent->right;
        newNode->middle = newChild;
        parent->right = child;
    } else {
        newNode->left = parent->right;
        newNode->middle = parent->middle;
        parent->right = newChild;
        parent->middle = child;
    }

    parent->key2 = parent->key1;
    parent->key1 = key;
    child->key2 = -1; // Mark the child as having only one key
}

struct Node* insertIntoNode(struct Node* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }

    if (node->key2 == -1) { // Node has one key
        if (key < node->key1) {
            node->key2 = node->key1;
            node->key1 = key;
        } else {
            node->key2 = key;
        }
    } else { // Node has two keys
        if (key < node->key1) {
            struct Node* newChild = insertIntoNode(node->left, key);
            splitNode(node, node->left, node->key1, newChild);
        } else if (key > node->key2) {
            struct Node* newChild = insertIntoNode(node->right, key);
            splitNode(node, node->right, node->key2, newChild);
        } else {
            struct Node* newChild = insertIntoNode(node->middle, key);
            splitNode(node, node->middle, key, newChild);
        }
    }

    return node;
}

struct Node* findMinNode(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct Node* deleteFromNode(struct Node* node, int key) {
    if (node == NULL) {
        return NULL;
    }

    if (key < node->key1) {
        node->left = deleteFromNode(node->left, key);
    } else if (key > node->key1 && (node->key2 == -1 || key < node->key2)) {
        node->middle = deleteFromNode(node->middle, key);
    } else if (key > node->key2) {
        node->right = deleteFromNode(node->right, key);
    } else {
        // Node with the key to be deleted found
        if (node->left == NULL && node->middle == NULL && node->right == NULL) {
            // Case 1: Node is a leaf, simply remove the key
            node->key1 = -1;
            node->key2 = -1;
        } else if (node->left != NULL && node->middle != NULL && node->right != NULL) {
            // Case 2: Node has three children
            // Find the minimum value in the right subtree and replace the key with it
            struct Node* minRight = findMinNode(node->right);
            node->key1 = minRight->key1;
            node->middle = deleteFromNode(node->middle, minRight->key1);
        } else {
            // Case 3: Node has two children
            if (node->left != NULL) {
                // Node has left child
                node->key1 = node->left->key1;
                node->key2 = -1;
                node->middle = node->left->middle;
                node->right = node->left->right;
                node->left = node->left->left;
            } else {
                // Node has right child
                node->key1 = node->right->key1;
                node->key2 = -1;
                node->middle = node->right->middle;
                node->right = node->right->right;
                node->left = node->right->left;
            }
        }
    }

    return node;
}

void deleteKey(struct Tree* tree, int key) {
    tree->root = deleteFromNode(tree->root, key);
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        if (root->key1 != -1) {
            printf(" %d", root->key1);
        }
        if (root->key2 != -1) {
            printf(" %d", root->key2);
        }
        inOrderTraversal(root->middle);
        inOrderTraversal(root->right);
    }
}

void displayTwoThreeTree(struct Tree* tree) {
    printf("2-3 Tree In-order Traversal:\n");
    inOrderTraversal(tree->root);
    printf("\n");
}

// Function to free the allocated memory for a 2-3 tree
void freeTwoThreeTree(struct Node* node) {
    if (node != NULL) {
        freeTwoThreeTree(node->left);
        freeTwoThreeTree(node->middle);
        freeTwoThreeTree(node->right);
        free(node);
    }
}

int main() {
    struct Tree* tree = createTree();
    int choice, key;

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertIntoNode(tree, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(tree, key);
                break;
            case 3:
                displayTwoThreeTree(tree);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free the allocated memory
    freeTwoThreeTree(tree->root);
    free(tree);

    return 0;
}
