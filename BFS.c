#include <stdio.h>
#include<malloc.h>

int q[100];
int f = -1, r = -1;

struct Node {
    int data;
    struct Node* nxt;
};

void ENQ(int data)
{
    if (r >= 100) {
        printf("Queue Overflow\n");
        return;
    }

    if (f == -1 && r == -1)
    {
        f = r = 0;
        q[r++] = data;
    }
    else
    {
        q[r++] = data;
    }
}

int pop()
{
    if (f == -1 || f >= r)
    {
        printf("Empty!\n");
        return -1;
    }
    else
    {
        int x = q[f++];
        return x;
    }
}

int isEmptyQueue()
{
    return f >= r;
}

void bfs(int A[100][100], int n, int st)
{
    int visited[100] = {0};

    visited[st] = 1;
    ENQ(st);
    while (!isEmptyQueue())
    {
        int x = pop();
        printf("%d\t", x);
        for (int i = 0; i < n; i++)
        {
            if (A[x][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                ENQ(i);
            }
        }
    }
}

void bfs2(struct Node* A[],int n,int st){
    int visited[100] = {0};
    visited[st] = 1;
    ENQ(st);
    while (!isEmptyQueue())
    {
        int x = pop();
        printf("%d\t",x);
        struct Node* p = A[x];
        while (p!=NULL)
        {
            /* code */
            if(visited[p->data] == 0){
                visited[p->data] = 1;
                ENQ(p->data);
            }
            p = p->nxt;
        }
        
    }
    
}

int main()
{
    int n;
    printf("Enter no. of vertices\n");
    scanf("%d", &n);
    char x;
    // if (n > 100) {
    //     printf("Too many vertices! Max allowed is 100.\n");
    //     return 1;
    // }

    // int A[100][100];

    // printf("Enter the adjacency matrix (0 or 1):\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         printf("Enter value for edge (%d, %d): ", i, j);
    //         int x;
    //         scanf("%d", &x);
    //         A[i][j] = x;
    //         A[j][i] = x;
    //     }
    // }
    struct Node* A[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = NULL;
    }
    do{
        int v1,v2;
        printf("Enter Vertex for having edge in between\n");
        scanf("%d %d",&v1,&v2);
        struct Node* new1,*new2;
        new1 = (struct Node*)malloc(sizeof(struct Node));
        new1->data = v2;
        new1->nxt = NULL;
        struct Node* p;
        p = A[v1];
        if(p==NULL){
            A[v1] = new1;
        }
        else{
            while (p->nxt != NULL)
            {
                /* code */
                p = p->nxt;
            }
            p->nxt = new1;
        }
        new2 = (struct Node*)malloc(sizeof(struct Node));
        new2->data = v1;
        new2->nxt = NULL;
        p = A[v2];
        if(p==NULL){
            p = new2;
            A[v2] = new2;
        }
        else{
            while (p->nxt != NULL)
            {
                /* code */
                p = p->nxt;
            }
            p->nxt = new2;
        }

        printf("\nWant to add more edges : (T/F) \n");
       
        scanf(" %c",&x);
        if(x=='F')break;
    }while(1);

    bfs2(A, n, 0);

    return 0;
}
