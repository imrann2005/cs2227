#include<stdio.h>
#include<stdlib.h>

struct Node
{
    /* data */
    int data;
    struct Node* next;
};

struct Node* sort(struct Node* curr,struct Node* head){
    
    if(head == NULL || head->data >= curr->data){
        curr -> next = head;
        head = curr;
    }
    else{
        struct Node* temp = head;
        struct Node* prev = NULL;
        while (temp!= NULL && temp->data <= curr->data)
        {
            /* code */
            prev = temp;
            temp = temp->next;
            
        }
        curr->next = temp;
        prev->next = curr;
    }
    return head;
}

struct Node* insertionSort(struct Node* head){
    struct Node* temp = head;
    struct Node* head2 = NULL;
    while (temp != NULL)
    {
        /* code */
        struct Node* next = temp->next;
        head2 = sort(temp,head2);
        temp = next;
    }
    return head2;
}

struct Node* display(struct Node* head){
    struct Node* temp = head;
    while (temp)
    {
        printf("%d\t",temp->data);
        temp = temp -> next;
    }
    return head;
}

int main(){

    int n;
    printf("Enter Number of Nodes\n");
    scanf("%d",&n);
    struct Node* head = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Enter Node : %d\n",i+1);
        scanf("%d",&x);
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = NULL;
        if(head == NULL){
            head = n;
        }
        else{
            struct Node* temp = head;
            while (temp->next != NULL)
            {
                /* code */
                temp = temp->next;
            }
            temp->next = n;
        }
    }
    head = insertionSort(head);
    head = display(head);
    return 0;
}