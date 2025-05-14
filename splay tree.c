#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node* rightRotate(struct Node* x) {
    struct Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

struct Node* splay(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    // Key is in the left subtree
    if (key < root->key) {
        // Key is not in the tree, we're done
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        // Zig (Left)
        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key is in the right subtree
    else {
        // Key is not in the tree, we're done
        if (root->right == NULL)
            return root;

        // Zig-Zag (Right Left)
        if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zig-Zig (Right Right)
        else if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        // Zig (Right)
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);

    // Splay the tree at the root with the new key
    root = splay(root, key);

    // Insert new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->key = key;
newNode->left = newNode->right = NULL;
    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }

    return newNode;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    // Splay the tree at the root with the key
    root = splay(root, key);

    // If the key is not present, return the root
    if (root->key != key)
        return root;

    // If the key is present, remove it
    struct Node* temp;
    if (root->left == NULL) {
        temp = root;
        root = root->right;
    } else {
        temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
    }

    free(temp);
    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf(" %d", root->key);
        inOrderTraversal(root->right);
    }
}

void displaySplayTree(struct Node* root) {
    printf("Splay Tree In-order Traversal:\n");
    inOrderTraversal(root);
    printf("\n");
}

// Function to free the allocated memory for a splay tree
void freeSplayTree(struct Node* node) {
    if (node != NULL) {
        freeSplayTree(node->left);
        freeSplayTree(node->right);
        free(node);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
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
                displaySplayTree(root);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free the allocated memory
    freeSplayTree(root);

    return 0;
}
