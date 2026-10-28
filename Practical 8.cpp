#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node *newNode(int key) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

Node *insertBST(Node *n, int key) {
    if (n == NULL)
        return newNode(key);

    if (key < n->key)
        n->left = insertBST(n->left, key);
    else if (key > n->key)
        n->right = insertBST(n->right, key);

    return n;
}

void inorder(Node *n) {
    if (n != NULL) {
        inorder(n->left);
        printf("%d ", n->key);
        inorder(n->right);
    }
}

void preorder(Node *n) {
    if (n != NULL) {
        printf("%d ", n->key);
        preorder(n->left);
        preorder(n->right);
    }
}

void postorder(Node *n) {
    if (n != NULL) {
        postorder(n->left);
        postorder(n->right);
        printf("%d ", n->key);
    }
}

int main(void) {
    Node *root = NULL;
    int a[] = {30, 20, 40, 10, 25};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++)
        root = insertBST(root, a[i]);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n");
    return 0;
}
