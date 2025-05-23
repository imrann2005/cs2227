#include <stdio.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int f(int dist[], int visited[], int n)
{
    int mn = 9999;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] < mn && visited[i] == 0)
        {
            mn = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstras(int A[][100], int n)
{
    int visited[n];
    int dist[n];
    printf("Enter Source Vertex\n");
    int v;
    scanf("%d", &v);

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        dist[i] = 999;
    }
    // visited[v] = 1;
    dist[v] = 0;
    int x = 0;
    while (1)
    {
        /* code */
        int u = f(dist, visited, n);
        if (u == -1)
            break;
        visited[u] = 1;
        for (int i = 0; i < n; i++)
        {
            if (A[u][i] > 0 && visited[i] == 0)
            {
                if (dist[u] + A[u][i] < dist[i])
                    dist[i] = dist[u] + A[u][i];
            }
        }
        //x++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", dist[i]);
    }
}

int main()
{
    int n;
    printf("Enter No. of vertices\n");
    scanf("%d", &n);
    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            printf("Enter Value at %d,%d cell\n", i, j);
            scanf("%d", &x);
            A[i][j] = x;
            // A[j][i] = x;
        }
    }
    dijkstras(A, n);
    return 0;
}