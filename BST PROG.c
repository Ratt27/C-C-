#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} N;

N *root = NULL;

int is_exist(N *rt, int val) {
    if (rt != NULL) {
        if (val > rt->data)
            return is_exist(rt->right, val);
        else if (val < rt->data)
            return is_exist(rt->left, val);
        else {
            return 1;
        }
    }
    return 0;
}

// insert function
N *insert(N *rt, N *nu) {
    if (rt != NULL) {
        if (nu->data > rt->data)
            rt->right = insert(rt->right, nu);
        else if (nu->data < rt->data)
            rt->left = insert(rt->left, nu);
        return rt;
    }
    return nu;
}

// creation
void create() {
    int val;
    N *nu;
    while (1) {
        printf("\nEnter data [0 to exit]: ");
        scanf("%d", &val);
        if (val == 0)
            break;
        if (is_exist(root, val) == 1) {
            printf("\nAlready exists, try again.");
            continue;
        }
        nu = (N *)malloc(sizeof(N));
        nu->data = val;
        nu->left = nu->right = NULL;
        root = insert(root, nu);
    }
}

void inorder(N *rt) {
    if (rt != NULL) {
        inorder(rt->left);
        printf("\n%d", rt->data);
        inorder(rt->right);
    }
}

void post_order(N *rt) {
    if (rt != NULL) {
        post_order(rt->left);
        post_order(rt->right);
        printf("\n%d", rt->data);
    }
}

void pre_order(N *rt) {
    if (rt != NULL) {
        printf("\n%d", rt->data);
        pre_order(rt->left);
        pre_order(rt->right);
    }
}

int main() {
    create();
    printf("\nInorder Traversal:");
    inorder(root);
    printf("\nPost-order Traversal:");
    post_order(root);
    printf("\nPre-order Traversal:");
    pre_order(root);

    return 0;
}
