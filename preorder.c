#include<stdio.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* st[100];
int top=-1;

void push(struct Node* data){
    top++;
    st[top] = data;
}

struct Node* pop(){
    return st[top--];
}

int emptyStack(){
    return top == -1;
}

void pre(struct Node* root){
    if(root != NULL){
        printf("%d\t",root->data);
        pre(root->left);
        pre(root->right);
    }
}
void in(struct Node* root){
    if(root != NULL){
        in(root->left);
        printf("%d\t",root->data);
        
        in(root->right);
    }
}
void post(struct Node* root){
    if(root != NULL){
        post(root->left);
        post(root->right);
        printf("%d\t",root->data);
      
    }
}

void preItr(struct Node* root){
    while (root!= NULL)
    {
        /* code */
        printf("%d\t",root->data);
        push(root);
        root = root->left;
    }
    while (!emptyStack())
    {
        /* code */
        struct Node* t = pop();
        t = t->right;
        while (t!=NULL)
        {
            /* code */
            printf("%d\t",t->data);
            push(t);
            t = t->left;
        }
        
    }
    
    
}

int main(){
    return 0;
}