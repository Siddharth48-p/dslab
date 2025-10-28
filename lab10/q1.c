#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) root = root->left;
    return root;
}

struct Node* findMax(struct Node* root) {
    while (root && root->right != NULL) root = root->right;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, val;
    while (1) {
        printf("\n1.Insert 2.Traversals 3.Search 4.Delete 5.Min/Max 6.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Inorder: "); inorder(root);
                printf("\nPreorder: "); preorder(root);
                printf("\nPostorder: "); postorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val)) printf("Found\n");
                else printf("Not Found\n");
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                printf("Deleted\n");
                break;
            case 5:
                if (root) {
                    printf("Min: %d\n", findMin(root)->data);
                    printf("Max: %d\n", findMax(root)->data);
                } else printf("Tree is empty\n");
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}
