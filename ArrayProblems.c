#include<stdio.h>

void sparse(int n,int m,int matrix[n][m]){
    int spMatrix[n*m+1][3];
    int idx = 0;
    spMatrix[idx][0] = n;
    spMatrix[idx][1] = m;
    idx++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(matrix[i][j] != 0){
                spMatrix[idx][0] = i;
                spMatrix[idx][1] = j;
                spMatrix[idx][2] = matrix[i][j];
                idx++;
            }
        }
        
    }
    spMatrix[0][2] = idx-1;

    for (int i = 0; i < idx; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t",spMatrix[i][j]);
        }
        printf("\n");
    }
    
}

int findSaddle(int n,int m,int arr[n][m]){
    for (int i = 0; i < n; i++)
    {
        int mn = 999;
        int col = -1;
        for (int j = 0; j < m; j++)
        {
            if(mn > arr[i][j]){
                mn = arr[i][j];
                col = j;
            }
        }
        int f = 0;
        for (int k = 0; k < n; k++)
        {
            if(arr[k][col] > mn){
                f = 1;
                break;
            }
        }
        if(f==0){
            printf("Saddle Pt : %d\n",mn);
            break;
        }
        
    }
    
}

int main(){
    // int n;
    // printf("Enter size of array\n");
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d",&arr[i]);
    // }
    int n,m;
    printf("Enter no of rows & cols\n");
    scanf("%d %d",&n,&m);
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            scanf("%d",&x);
            a[i][j] = x;
        }
        
    }
    sparse(n,m,a);
    findSaddle(n,m,a);
    return 0;
}