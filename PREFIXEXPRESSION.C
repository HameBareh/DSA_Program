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
    char prefix[20];
    int i;
    int a, b, result;

    clrscr();

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    /* Scan from right to left */
    for(i = 0; prefix[i] != '\0'; i++)
    {
        /* Find the length and start from the last character */
    }

    i = i - 1;

    while(i >= 0)
    {
        if(isdigit(prefix[i]))
        {
            push(prefix[i] - '0');
        }
        else
        {
            a = pop();
            b = pop();

            switch(prefix[i])
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

        i--;
    }

    result = pop();

    printf("Result = %d", result);

    getch();
}