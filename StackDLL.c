#include<stdio.h>
#include<stdlib.h>

struct DLL{
    int data;
    struct DLL* prev;
    struct DLL* next;

};

struct DLL* top = NULL;

void push(int data){
    struct DLL* n = (struct DLL*)malloc(sizeof(struct DLL));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    if(top == NULL){
        top = n;
    }
    else{
        top->next = n;
        n->prev = top;
        top = top->next;
    }
}

int pop(){
    if(top != NULL){
        struct DLL* cpy = top;
        top = top->prev;
        cpy->prev = NULL;
        cpy->next = NULL;
        int d = cpy->data;
        free(cpy);
        return d;
    }
    else return -1;
}

int main(){
    push(100);
    push(300);
    push(200);
    printf("%d\t",pop());
    printf("%d\t",pop());
    push(120);
    printf("%d\t",pop());
    return 0;
}