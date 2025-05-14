#include <stdio.h>
#include <stdlib.h>

#define DEGREE 2

struct BTreeNode {
    int n;
    int keys[2 * DEGREE - 1];
    struct BTreeNode* children[2 * DEGREE];
    int leaf;
};

struct BTreeNode* createNode() {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    newNode->n = 0;
    newNode->leaf = 1;
    return newNode;
}

void splitChild(struct BTreeNode* parent, int index, struct BTreeNode* child) {
	int i;
    struct BTreeNode* newNode = createNode();
    newNode->leaf = child->leaf;
    newNode->n = DEGREE - 1;

    for ( i = 0; i < DEGREE - 1; i++) {
        newNode->keys[i] = child->keys[i + DEGREE];
    }

    if (!child->leaf) {
        for ( i = 0; i < DEGREE; i++) {
            newNode->children[i] = child->children[i + DEGREE];
        }
    }

    child->n = DEGREE - 1;

    for (i = parent->n; i > index; i--) {
        parent->children[i + 1] = parent->children[i];
    }

    parent->children[index + 1] = newNode;

    parent->keys[index] = child->keys[DEGREE - 1];

    parent->n++;
}

void insertNonFull(struct BTreeNode* node, int key) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }

        i++;

        if (node->children[i]->n == 2 * DEGREE - 1) {
            splitChild(node, i, node->children[i]);

            if (key > node->keys[i]) {
                i++;
            }
        }

        insertNonFull(node->children[i], key);
    }
}

struct BTreeNode* insert(struct BTreeNode* root, int key) {
    if (root->n == 2 * DEGREE - 1) {
        struct BTreeNode* newRoot = createNode();
        newRoot->leaf = 0;
        newRoot->children[0] = root;
        splitChild(newRoot, 0, root);
        insertNonFull(newRoot, key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

int findPredecessor(struct BTreeNode* node) {
    while (!node->leaf) {
        node = node->children[node->n];
    }

    return node->keys[node->n - 1];
}

int findSuccessor(struct BTreeNode* node) {
    while (!node->leaf) {
        node = node->children[0];
    }

    return node->keys[0];
}

struct BTreeNode* removeKey(struct BTreeNode* root, int key) {
    int index = 0,i;
    while (index < root->n && key > root->keys[index]) {
        index++;
    }

    if (index < root->n && root->keys[index] == key) {
        if (root->leaf) {
            for (i = index + 1; i < root->n; i++) {
                root->keys[i - 1] = root->keys[i];
            }
            root->n--;
        } else {
            int predecessor = findPredecessor(root->children[index]);
            root->keys[index] = predecessor;
            root->children[index] = removeKey(root->children[index], predecessor);
        }
    } else {
        struct BTreeNode* child = root->children[index];

        if (child->n == DEGREE - 1) {
            if (index != 0 && root->children[index - 1]->n >= DEGREE) {
                // Borrow from the previous child
            } else if (index != root->n && root->children[index + 1]->n >= DEGREE) {
                // Borrow from the next child
            } else {
                // Merge with the next child
            }
        }

        root->children[index] = removeKey(child, key);
    }

    return root;
}

void inOrderTraversal(struct BTreeNode* node) {
    int i;
    for (i = 0; i < node->n; i++) {
        if (node->leaf == 0) {
            inOrderTraversal(node->children[i]);
        }
        printf(" %d", node->keys[i]);
    }

    if (node->leaf == 0) {
        inOrderTraversal(node->children[i]);
    }
}

void displayBTree(struct BTreeNode* root) {
    if (!root) {
        printf("The B-tree is empty.\n");
        return;
    }

    printf("B-tree In-order Traversal:\n");
    inOrderTraversal(root);
    printf("\n");
}

void freeBTree(struct BTreeNode* node) {
	int i;
    if (node->leaf == 0) {
        for ( i = 0; i <= node->n; i++) {
            freeBTree(node->children[i]);
        }
    }
    free(node);
}

int main() {
    struct BTreeNode* root = createNode();
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
                root = removeKey(root, key);
                break;
            case 3:
                displayBTree(root);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free the allocated memory
    freeBTree(root);

    return 0;
}
