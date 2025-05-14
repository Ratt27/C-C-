#include <stdio.h>
#include <stdlib.h>

#define ALPHA 0.7  // Parameter for balancing condition

// Structure for a node in the scapegoat tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform an inorder traversal and display the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to calculate the size of the tree
int size(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}
// Helper function to store nodes of the tree in an array (inorder traversal)

void storeNodes(struct Node* root, struct Node* nodes[], int* index) {
    if (root != NULL) {
        storeNodes(root->left, nodes, index);
        nodes[(*index)++] = root;
        storeNodes(root->right, nodes, index);
    }
}
// Helper function to build a balanced tree from a sorted array of nodes
struct Node* buildBalancedTree(struct Node* nodes[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    struct Node* root = nodes[mid];

    root->left = buildBalancedTree(nodes, start, mid - 1);
    root->right = buildBalancedTree(nodes, mid + 1, end);

    return root;
}


// Function to rebuild the subtree rooted at 'root' as a balanced binary search tree
struct Node* rebuild(struct Node* root, int count) {
    struct Node* nodes[count];
    int index = 0;
    storeNodes(root, nodes, &index);

    return buildBalancedTree(nodes, 0, count - 1);
}




// Function to insert a node in the scapegoat tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    int leftSize = size(root->left);
    int rightSize = size(root->right);
    int currentSize = 1 + leftSize + rightSize;

    // Check if the tree is unbalanced
    if (leftSize > ALPHA * currentSize || rightSize > ALPHA * currentSize) {
        // If unbalanced, find the scapegoat node and rebuild the subtree
        return rebuild(root, currentSize);
    }

    return root;
}

// Function to find the minimum value node in a tree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the scapegoat tree
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    int leftSize = size(root->left);
    int rightSize = size(root->right);
    int currentSize = 1 + leftSize + rightSize;

    // Check if the tree is unbalanced
    if (leftSize > ALPHA * currentSize || rightSize > ALPHA * currentSize) {
        // If unbalanced, find the scapegoat node and rebuild the subtree
        return rebuild(root, currentSize);
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Tree elements: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    // TODO: Free the memory allocated for the tree nodes (not implemented in this example)

    return 0;
}
