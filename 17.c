#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Stack {
    struct Node* data[100];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, struct Node* node) {
    s->data[++s->top] = node;
}

struct Node* pop(struct Stack* s) {
    return s->data[s->top--];
}

void inorderRec(struct Node* root) {
    if (root == NULL) return;
    inorderRec(root->left);
    printf("%d ", root->data);
    inorderRec(root->right);
}

void preorderRec(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderRec(root->left);
    preorderRec(root->right);
}

void postorderRec(struct Node* root) {
    if (root == NULL) return;
    postorderRec(root->left);
    postorderRec(root->right);
    printf("%d ", root->data);
}

void inorderIter(struct Node* root) {
    struct Stack s;
    initStack(&s);
    struct Node* current = root;
    while (current != NULL || !isEmpty(&s)) {
        while (current != NULL) {
            push(&s, current);
            current = current->left;
        }
        current = pop(&s);
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorderIter(struct Node* root) {
    if (root == NULL) return;
    struct Stack s;
    initStack(&s);
    push(&s, root);
    while (!isEmpty(&s)) {
        struct Node* current = pop(&s);
        printf("%d ", current->data);
        if (current->right)
            push(&s, current->right);
        if (current->left)
            push(&s, current->left);
    }
}

void postorderIter(struct Node* root) {
    if (root == NULL) return;
    struct Stack s1, s2;
    initStack(&s1);
    initStack(&s2);
    push(&s1, root);
    while (!isEmpty(&s1)) {
        struct Node* current = pop(&s1);
        push(&s2, current);
        if (current->left)
            push(&s1, current->left);
        if (current->right)
            push(&s1, current->right);
    }
    while (!isEmpty(&s2)) {
        printf("%d ", pop(&s2)->data);
    }
}

int main() {
    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int choice1, choice2;
    do {
        printf("\nMenu:\n1. Recursive\n2. Iterative\n0. Exit\nEnter choice: ");
        scanf("%d", &choice1);
        if (choice1 == 0)
            break;

        printf("Traversal type:\n1. Inorder\n2. Preorder\n3. Postorder\nEnter choice: ");
        scanf("%d", &choice2);

        printf("Result: ");
        if (choice1 == 1) {
            if (choice2 == 1)
                inorderRec(root);
            else if (choice2 == 2)
                preorderRec(root);
            else if (choice2 == 3)
                postorderRec(root);
            else
                printf("Invalid choice!");
        }
        else if (choice1 == 2) {
            if (choice2 == 1)
                inorderIter(root);
            else if (choice2 == 2)
                preorderIter(root);
            else if (choice2 == 3)
                postorderIter(root);
            else
                printf("Invalid choice!");
        }
        else {
            printf("Invalid choice!");
        }
        printf("\n");
    } while (1);

    printf("Program exited.\n");
    return 0;
}
