#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with a given key into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is smaller than the root's key
    if (key < root->data)
        return search(root->left, key);

    // Key is larger than the root's key
    return search(root->right, key);
}

// Function to perform in-order traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
	 int i;
    struct Node* root = NULL;

    // User input to build the BST
    int n, key;
    printf("Enter the number of elements: ");
    if (scanf("%d",&n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a valid positive integer.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for ( i = 0; i < n; i++) {
        if (scanf("%d",&key) != 1) {
            printf("Invalid input. Please enter valid integers.\n");
            return 1;
        }
        root = insert(root, key);
    }

    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // User input to search for a key in the BST
    int keyToSearch;
    printf("Enter the element to search: ");
    if (scanf("%d",&keyToSearch) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    struct Node* result = search(root, keyToSearch);

    if (result != NULL)
        printf("%d found in the BST.\n", keyToSearch);
    else
        printf("%d not found in the BST.\n", keyToSearch);

    return 0;
}
