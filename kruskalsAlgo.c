#include <stdio.h>

int f(int a, int parent[])
{
    while (a != parent[a])
    {
        /* code */
        a = parent[a];
    }
    return a;
}

void kruskals(int A[][100], int n)
{
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int ne = 1;
    int mn = 999;
    int a, b, u, v;
    int cst = 0;
    while (ne < n)
    {
        /* code */
        mn = 999;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mn > A[i][j])
                {
                    mn = A[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }
        u = f(a, parent);
        v = f(b, parent);
        if (u != v)
        {
            parent[u] = v;
            printf("Edge Added b/w %d-%d with cost=%d \n", a, b, A[a][b]);
            ne++;
            cst += A[a][b];
           

        }
         A[a][b] = A[b][a] = 99;
    }
    printf("Min Cost = %d\n",cst);

}

int main()
{
    int n;
    printf("Enter No. of vertices\n");
    scanf("%d", &n);
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
    kruskals(A,n);
    return 0;
}