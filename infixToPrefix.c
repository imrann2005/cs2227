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

void infixToPrefix(char str[100])
{
    char str2[100];
    int n = strlen(str);
    char ans[100];
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[n - i - 1] == '(')
        {
            str2[i] = ')';
        }
        else if (str[n - i - 1] == ')')
        {
            str2[i] = '(';
        }
        else
            str2[i] = str[n - i - 1];
    }
    int i = 0;
    while (i < n)
    {

        if (str2[i] >= 'a' && str2[i] <= 'z')
        {
            //printf("%c", str2[i]);
            ans[idx++] = str2[i];
        }
        else if (str2[i] == '(')
        {
            push(str2[i]);
        }
        else if (str2[i] == ')')
        {
            while (!emptyStack() && stack[top] != '(')
            {
                /* code */
                char x = pop();
                ans[idx++] = x;
            }
            pop();
        }
        else
        {
            if (str2[i] == '^')
            {
                while (!emptyStack() && priority(str2[i]) <= priority(stack[top]))
                {
                    /* code */
                    char x = pop();
                    ans[idx++] = x;
                }
            }
            else
            {
                while (!emptyStack() && priority(str2[i]) < priority(stack[top]))
                {
                    /* code */
                    char x = pop();
                    ans[idx++] = x;
                }
            }
            push(str2[i]);
        }
        i++;
    }
    while (!emptyStack())
    {
        /* code */
        char x = pop();
        ans[idx++] = x;
    }
    n = strlen(ans);
    for (int i = 0; i < n; i++)
    {
        
        printf("%c",ans[n-i-1]);
    }
    
}

int main()
{
    char str[100];
    printf("Enter Infix Expression\n");
    scanf("%s", &str);
    infixToPrefix(str);
    return 0;
}