#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

void in(struct Node *root)
{
    if (root != NULL)
    {
        in(root->left);
        printf("%d\t", root->data);

        in(root->right);
    }
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

int searchBST(struct Node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return 1;
    }
    if (key < root->data)
    {
        return searchBST(root->left, key);
    }
    return searchBST(root->right, key);
}

void mirrorImg(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    mirrorImg(root->left);
    mirrorImg(root->right);
    struct Node *temp = root->right;
    root->right = root->left;
    root->left = temp;
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
    in(root);
   
    return 0;
}