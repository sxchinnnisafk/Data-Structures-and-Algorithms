#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item)
{
    if (top < MAX - 1)
        stack[++top] = item;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

int precedence(char symbol)
{
    switch (symbol)
    {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char item, x;

    push('(');
    strcat(infix, ")");

    i = 0;
    item = infix[i];

    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isalnum(item))
        {
            postfix[j++] = item;
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix[j++] = x;
                x = pop();
            }
        }
        else
        {
            while ((precedence(stack[top]) > precedence(item)) ||
                   (precedence(stack[top]) == precedence(item) && item != '^'))
            {
                postfix[j++] = pop();
            }
            push(item);
        }

        item = infix[++i];
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
