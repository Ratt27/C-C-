#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    int priority;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->priority = rand(); // Random priority for the treap
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key <= root->key) {
        root->left = insert(root->left, key);

        // Rotate right if the priority of the left child is higher
        if (root->left->priority > root->priority) {
            root = rightRotate(root);
        }
    } else {
        root->right = insert(root->right, key);

        // Rotate left if the priority of the right child is higher
        if (root->right->priority > root->priority) {
            root = leftRotate(root);
        }
    }

    return root;
}

Node* deleteNode(Node* root, int key) {
    // TODO: Implement deletion
    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    srand(time(NULL));

    Node* root = NULL;
    int choice, key;

    do {
        printf("\n1. Insert\n2. Delete\n3. Display (Inorder Traversal)\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
