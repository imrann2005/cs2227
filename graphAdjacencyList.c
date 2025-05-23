#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node* nxt;
};

int main(){
    int n;
    char x = '0';
    printf("Enter no. of vertices\n");
    scanf("%d",&n);
    //struct Node* A = (struct Node*)malloc(n*sizeof(struct Node));
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

    for (int i = 0; i < n; i++)
    {
        struct Node* p;
        p = A[i];
        printf("%d\t",i);
        while (p!=NULL)
        {
            /* code */
            printf("%d\t",p->data);
            p = p->nxt;
        }
        printf("\n");
    }
    
}