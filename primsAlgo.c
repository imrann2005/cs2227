#include <stdio.h>
#define V 5

int minKey(int key[], int set[])
{
    int mn = 100, idx = -1;
    for (int i = 0; i < V; i++)
    {
        if (set[i] == 0 && mn < key[i])
        {
            mn = key[i];
            idx = i;
        }
    }

    return idx;
}

void display(int parent[], int G[V][V])
{
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d-%d\t%d\n", parent[i], i, G[i][parent[i]]);
    }
}

void prims(int G[V][V])
{
    int parent[10], key[10], set[10], u;
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        key[i] = 99;
        set[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++)
    {
        /* code */
        u = minKey(key, set);
        set[u] = 1;
        for (int j = 0; j < V; j++)
        {
            /* code */
            if (G[u][j] != 99 && set[i] != 0 && G[u][j] < key[j])
            {
                key[j] = G[u][j];
                parent[j] = u;
            }
        }
    }
    display(parent, G);
}

int main()
{
    int A[V][V];

    printf("Enter Adjaceny Matrix 5x5\n");
    for (int i = 0; i < V; i++)
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
    prims(A);
    return 0;
}