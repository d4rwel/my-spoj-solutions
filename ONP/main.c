#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN_EXPR 400

typedef struct {
        char data[LEN_EXPR];
        int size;
} Stack;

void Stack_Init(Stack *S) 
{
        S->size = 0;
}

char Stack_Top(Stack *S) 
{
        if(S->size == 0) {
                printf("Error: stack empty\n");
                return -1;
        }

        return S->data[S->size - 1];
}

void Stack_Push(Stack *S, char c)
{
        if(S->size < LEN_EXPR)
                S->data[S->size++] = c;
        else
                printf("Error: stack full\n");
}

void Stack_Pop(Stack *S)
{
        if(S->size == 0)
                printf("Error: stack empty\n");
        else {
                S->size--;
        }
}

bool isOperator(char c)
{
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
                return true;
        else
                return false;
}

bool cmpOperator(char c1, char c2)
{
        int a, b = 0;

        switch(c1)
        {
                case '+': 
                case '-': 
                        a = 0; break;
                case '*': 
                case '/': 
                        a = 1; break;
                case '^': 
                        a = 2; break;
                default: a = 0;
        }

        switch(c2)
        {
                case '+': 
                case '-': 
                        b = 0; break;
                case '*': 
                case '/': 
                        b = 1; break;
                case '^': 
                        b = 2; break;
                default: b = 0;
        }

        return a < b; 
}



int main(int argc, char *argv[]) 
{
        int i = 0;
        int j = 0;
        int k = 0;
        int num_expr = 0;

        char token;
        char (*input)[LEN_EXPR + 1];
        char (*ptr)[LEN_EXPR + 1];
        char output[LEN_EXPR];

        Stack *stack;
        stack = malloc(sizeof(Stack));

        scanf("%d", &num_expr);
        if(num_expr > 100) return 1;

        input = malloc(num_expr * sizeof(char[LEN_EXPR + 1]));

        ptr = input;

        for(i = 0; i < num_expr; i++, ptr++) 
        {
                scanf("%s", *ptr);
                if(strlen(*ptr) > LEN_EXPR) return 1;
        }
        
        ptr = input;

        for(i = 0; i < num_expr; i++, ptr++)
        {
                j = 0;
                k = 0;

                Stack_Init(stack);

                while((*ptr)[j] != '\0')
                {
                        token = (*ptr)[j];

                        if(token >= 'a' && token <= 'z') {
                                output[k++] = token;
                        } else if(isOperator(token)) {
                                while(stack->size != 0 
                                                && isOperator(Stack_Top(stack))
                                                && cmpOperator(token, Stack_Top(stack)))
                                {
                                        output[k++] = Stack_Top(stack);
                                        Stack_Pop(stack);
                                }
                                Stack_Push(stack, token);
                        } else if(token == '(') {
                                Stack_Push(stack, token);
                        } else if(token == ')') {
                                while(Stack_Top(stack) != '(') {
                                        output[k++] = Stack_Top(stack);
                                        Stack_Pop(stack);
                                }
                                Stack_Pop(stack);
                        }

                        j++;
                }

                while(stack->size != 0)
                {
                        output[k++] = Stack_Top(stack);
                        Stack_Pop(stack);
                }

                output[k] = '\0';
                printf("%s\n", output);
        }

        free(stack);
        free(input);

        return 0;
}
