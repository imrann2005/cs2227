#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *stack[100];
int top = -1;

void push(struct Node *t)
{
    top++;
    stack[top] = t;
}

struct Node *pop()
{
    return stack[top--];
}

int isEmptyStack()
{
    return top == -1;
}

struct Node *insertBST(struct Node *root, int x)
{
    struct Node *temp = root;
    struct Node *parent = NULL;
    struct Node *xN = (struct Node *)malloc(sizeof(struct Node));
    xN->data = x;
    xN->left = NULL;
    xN->right = NULL;
    while (temp != NULL)
    {
        /* code */
        parent = temp;
        if (temp->data < x)
        {
            temp = temp->right;
        }
        else
            temp = temp->left;
    }
    if (x < parent->data)
    {
        parent->left = xN;
    }
    else
        parent->right = xN;

    return root;
}

void preOrderNonRec(struct Node *root)
{
    push(root);
    while (!isEmptyStack())
    {
        /* code */
        struct Node *t = pop();
        printf("%d\t", t->data);
        if (t->right)
            push(t->right);
        if (t->left)
            push(t->left);
    }
}

void postOrderNonRec(struct Node *root)
{
}

void inOrderNonRec(struct Node *root)
{
    int cnt = 0;
    while (root != NULL)
    {
        /* code */
        push(root);
        root = root->left;
    }
    while (!isEmptyStack())
    {
        /* code */
        struct Node *t = pop();
        printf("%d\t", t->data);
        cnt++;
        t = t->right;
        while (t != NULL)
        {
            /* code */
            push(t);
            t = t->left;
        }
    }
    printf("No. of nodes : %d\n", cnt);
}

void displayLeafNodes(struct Node *root)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            printf("%d\t", root->data);
        }

        displayLeafNodes(root->left);
        displayLeafNodes(root->right);
    }
}

int main()
{
    printf("Enter the No. of nodes\n");
    int n;
    scanf("%d", &n);
    struct Node *root;
    root = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->left = NULL;
        n->right = NULL;
        n->data = x;
        if (root == NULL)
        {
            root = n;
        }
        else
        {
            root = insertBST(root, x);
        }
    }
    preOrderNonRec(root);
    inOrderNonRec(root);
    displayLeafNodes(root);
    return 0;
}