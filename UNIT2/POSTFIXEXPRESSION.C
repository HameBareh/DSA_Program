#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int stack[20];
int top = -1;

void push(int value)
{
    top++;
    stack[top] = value;
}

int pop()
{
    int value;

    value = stack[top];
    top--;

    return value;
}

void main()
{
    char postfix[20];
    int i;
    int a, b, result;

    clrscr();

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch(postfix[i])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;
            }

            push(result);
        }
    }

    result = pop();

    printf("Result = %d", result);

    getch();
}
