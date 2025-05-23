#include <stdio.h>
#include <malloc.h>
int st[100];
int top = -1;

void push(int data)
{
    top++;
    st[top] = data;
}

int pop()
{
    if (top == -1)
    {
        return -1;
    }
    return st[top--];
}

int emptyStack()
{
    return top == -1;
}

struct Node
{
    int data;
    struct Node *nxt;
};

void DFS1(struct Node *A[], int n)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    struct Node *p;
    int v;
    printf("Enter start Vertex\n");
    scanf("%d", &v);
    visited[v] = 1;
    printf("%d\t", v);
    push(v);
    while (!emptyStack())
    {
        /* code */
        p = A[v];
        while (p != NULL)
        {
            /* code */
            if (visited[p->data] == 0)
            {
                push(p->data);
                printf("%d\t", p->data);
                visited[p->data] = 1;
                v = p->data;
                break;
            }
            p = p->nxt;
        }
        if (p == NULL)
        {
            int x = pop();
            if (!emptyStack())
            {
                v = st[top];
            }
        }
    }
}

void DFS2()
{
    int n;
    printf("Enter No. of vertices\n");
    scanf("%d", &n);
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x;
            printf("Enter Value at %d,%d cell\n", i, j);
            scanf("%d", &x);
            A[i][j] = x;
            A[j][i] = x;
        }
    }
    printf("Enter Start Vertex\n");
    int v;
    scanf("%d", &v);
    push(v);
    printf("%d\t", v);
    visited[v] = 1;

    while (!emptyStack())
    {
        /* code */
        int x = v;
        int f = 1;
        for (int i = 0; i < n; i++)
        {
            if (A[x][i] == 1 && visited[i] == 0)
            {
                f = 0;
                visited[i] = 1;
                printf("%d\t", i);
                push(i);
                v = i;
                break;
            }
        }
        if (f)
        {
            int e = pop();
            if (!emptyStack())
            {
                v = st[top];
            }
        }
    }
}

int main()
{
    //     int n;
    //     char x = '0';
    //     printf("Enter no. of vertices\n");
    //     scanf("%d", &n);
    //     // struct Node* A = (struct Node*)malloc(n*sizeof(struct Node));
    //     struct Node *A[n];
    //     for (int i = 0; i < n; i++)
    //     {
    //         A[i] = NULL;
    //     }
    //     do
    //     {
    //         int v1, v2;
    //         printf("Enter Vertex for having edge in between\n");
    //         scanf("%d %d", &v1, &v2);
    //         struct Node *new1, *new2;
    //         new1 = (struct Node *)malloc(sizeof(struct Node));
    //         new1->data = v2;
    //         new1->nxt = NULL;
    //         struct Node *p;
    //         p = A[v1];
    //         if (p == NULL)
    //         {
    //             A[v1] = new1;
    //         }
    //         else
    //         {
    //             while (p->nxt != NULL)
    //             {
    //                 /* code */
    //                 p = p->nxt;
    //             }
    //             p->nxt = new1;
    //         }
    //         new2 = (struct Node *)malloc(sizeof(struct Node));
    //         new2->data = v1;
    //         new2->nxt = NULL;
    //         p = A[v2];
    //         if (p == NULL)
    //         {
    //             p = new2;
    //             A[v2] = new2;
    //         }
    //         else
    //         {
    //             while (p->nxt != NULL)
    //             {
    //                 /* code */
    //                 p = p->nxt;
    //             }
    //             p->nxt = new2;
    //         }

    //         printf("\nWant to add more edges : (T/F) \n");

    //         scanf(" %c", &x);
    //         if (x == 'F')
    //             break;
    //     } while (1);
    //     DFS1(A,n);
    //     // for (int i = 0; i < n; i++) {
    //     // struct Node* temp = A[i];
    //     // while (temp != NULL) {
    //     //     struct Node* next = temp->nxt;
    //     //     free(temp);
    //     //     temp = next;
    //     // }
    // }

    DFS2();
    return 0;
}