#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

struct Node {
    int data;
    enum Color color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};

struct Tree {
    struct Node* root;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are always red
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Tree* createTree() {
    struct Tree* newTree = (struct Tree*)malloc(sizeof(struct Tree));
    newTree->root = NULL;
    return newTree;
}

void leftRotate(struct Tree* tree, struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void rightRotate(struct Tree* tree, struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;

    if (x->right != NULL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NULL) {
        tree->root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

void insertFixup(struct Tree* tree, struct Node* z) {
    while (z->parent != NULL && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            struct Node* y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(tree, z->parent->parent);
            }
        } else {
            struct Node* y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(tree, z->parent->parent);
            }
        }
    }

    tree->root->color = BLACK;
}

void insert(struct Tree* tree, int data) {
    struct Node* z = createNode(data);
    struct Node* y = NULL;
    struct Node* x = tree->root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == NULL) {
        tree->root = z; // Tree was empty
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    insertFixup(tree, z);
}

struct Node* treeMinimum(struct Node* x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

void deleteFixup(struct Tree* tree, struct Node* x) {
    while (x != tree->root && (x == NULL || x->color == BLACK)) {
        if (x == x->parent->left) {
            struct Node* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(tree, x->parent);
                w = x->parent->right;
            }
            if ((w->left == NULL || w->left->color == BLACK) &&
                (w->right == NULL || w->right->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right == NULL || w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(tree, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(tree, x->parent);
                x = tree->root; // Exit the loop
            }
        } else {
            struct Node* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(tree, x->parent);
                w = x->parent->left;
            }
            if ((w->right == NULL || w->right->color == BLACK) &&
                (w->left == NULL || w->left->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left == NULL || w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(tree, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(tree, x->parent);
                x = tree->root; // Exit the loop
            }
        }
    }

    if (x != NULL) {
        x->color = BLACK;
    }
}

void transplant(struct Tree* tree, struct Node* u, struct Node* v) {
    if (u->parent == NULL) {
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}

void deleteNode(struct Tree* tree, struct Node* z) {
    struct Node* y = z;
    struct Node* x;
    enum Color yOriginalColor = y->color;

    if (z->left == NULL) {
        x = z->right;
        transplant(tree, z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        transplant(tree, z, z->left);
    } else {
        y = treeMinimum(z->right);
        yOriginalColor = y->color;
        x = y->right;

        if (y->parent == z) {
            if (x != NULL) {
                x->parent = y;
            }
        } else {
            transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    free(z);

    if (yOriginalColor == BLACK) {
        deleteFixup(tree, x);
    }
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf(" %d", root->data);
        inOrderTraversal(root->right);
    }
}

void displayRedBlackTree(struct Tree* tree) {
    printf("Red-Black Tree In-order Traversal:\n");
    inOrderTraversal(tree->root);
    printf("\n");
}

void freeRedBlackTree(struct Node* node) {
    if (node != NULL) {
        freeRedBlackTree(node->left);
        freeRedBlackTree(node->right);
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
                insert(tree, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                // Assume the key to delete is present in the tree
                deleteNode(tree, tree->root);
                break;
            case 3:
                displayRedBlackTree(tree);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free the allocated memory
    freeRedBlackTree(tree->root);
    free(tree);

    return 0;
}
