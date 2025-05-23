#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];

int top = -1;

void push(char c)
{
    top++;
    stack[top] = c;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return -1;
}

int emptyStack()
{
    return top == -1;
}

void infixToPostfix(char str[100])
{
    int i = 0;
    int n = strlen(str);
    while (i < n)
    {
        /* code */
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            printf("%c", str[i]);
        }
        else if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!emptyStack() && stack[top] != '(')
            {
                /* code */
                char x = pop();
                printf("%c", x);
            }
            pop();
        }
        else
        {
            while (!emptyStack() && priority(str[i]) <= priority(stack[top]))
            {
                /* code */
                char x = pop();
                printf("%c", x);
            }
            push(str[i]);
        }
        i++;
    }
    while (!emptyStack())
    {
        /* code */
        char x = pop();
        printf("%c", x);
    }
}

int main()
{
    char str[100];
    printf("Enter Infix Expression\n");
    scanf("%s", &str);
    printf("%d\n",strlen(str));
    infixToPostfix(str);
    return 0;
}