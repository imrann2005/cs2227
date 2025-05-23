#include<stdio.h>
#include<stdlib.h>

struct Node
{
    /* data */
    int data;
    struct Node* next;
};

struct Node* findMiddle(struct Node* head){
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        /* code */
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast == NULL)return prev;
    return slow;
}

struct Node* merge(struct Node* head1,struct Node* head2){
    if(head1 == NULL)return head2;
    if(head2 == NULL)return head1;

    struct Node* dh = (struct Node*)malloc(sizeof(struct Node));
    dh -> data = -1;
    struct Node* t1 = head1;
    struct Node* t2 = head2;
    struct Node* t3 = dh;
    while (t1 && t2)
    {
        /* code */
        if(t1->data <= t2->data){
            t3->next = t1;
            t1 = t1->next;
            t3 = t3->next;
        }
        else
        {
            t3->next = t2;
            t2 = t2->next;
            t3 = t3->next;
        }
        
    }

    while (t1 != NULL)
    {
        /* code */
        t3->next = t1;

        t1 = t1->next;
        t3 = t3->next;
    }

    while (t2 != NULL)
    {
        /* code */
        t3->next = t2;
        t2 = t2->next;
        t3 = t3->next;
    }
    
    return dh->next;
    
}

struct Node* mergeSort(struct Node* head){
    if(head == NULL || head -> next == NULL)return head;
    struct Node* mid = findMiddle(head);
    struct Node* head2 = mid->next;
    mid->next = NULL;
    head = mergeSort(head);
    head2 = mergeSort(head2);
    return merge(head,head2);
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
    head = mergeSort(head);
    head = display(head);
    return 0;
}
