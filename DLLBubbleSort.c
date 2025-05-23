#include <stdlib.h>
#include <stdio.h>

struct DLL
{
    int data;
    struct DLL *next;
    struct DLL *prev;
};

struct DLL *bubbleSort(struct DLL *head)
{
    struct DLL *dummy = head;
    struct DLL *temp = head;
    struct DLL *prev = NULL;
    int f = 0;
    while (1)
    {
        /* code */
        f = 1;
        temp = dummy;
        prev = temp;
        temp = temp->next;
        while (temp != NULL)
        {
            if (prev->data > temp->data)
            {
                int x = prev->data;
                prev->data = temp->data;
                temp->data = x;
                f = 0;
            }
            prev = temp;
            temp = temp->next;
            /* code */
        }
        if (f)
        {
            break;
        }
    }

    return head;
}

struct DLL* display(struct DLL* head){
    struct DLL* temp = head;
    while (temp)
    {
        printf("%d\t",temp->data);
        temp = temp -> next;
    }
    return head;
}

int main()
{
    int n;
    scanf("%d", &n);
    struct DLL *head = NULL;

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        struct DLL *n = (struct DLL *)malloc(sizeof(struct DLL));
        n->data = x;
        n->next = NULL;
        n->prev = NULL;
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            struct DLL *temp = head;
            while (temp->next != NULL)
            {
                /* code */
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
        }
    }
    head = bubbleSort(head);
    head = display(head);
    return 0;
}