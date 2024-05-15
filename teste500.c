


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define STACK_SIZE 100

// Definição da estrutura de uma pilha
typedef struct {
    double items[STACK_SIZE];
    int top;
} Stack;

// Funções da pilha
void push(Stack *stack, double value) {
    if (stack->top < STACK_SIZE - 1) {
        stack->top++;
        stack->items[stack->top] = value;
    } else {
        printf("Erro: Pilha cheia!\n");
        exit(EXIT_FAILURE);
    }
}

double pop(Stack *stack) {
    if (stack->top >= 0) {
        double value = stack->items[stack->top];
        stack->top--;
        return value;
    } else {
        printf("Erro: Pilha vazia!\n");
        exit(EXIT_FAILURE);
    }
}

double evaluateExpression(const char *expression) {
    Stack stack;
    stack.top = -1;

    char *token = strtok((char *)expression, " ");

    while (token != NULL) {
        if (isdigit(*token)) {
            push(&stack, atof(token));
        } else {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            double result;

            switch (*token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0)
                        result = operand1 / operand2;
                    else {
                        printf("Erro: Divisão por zero!\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    printf("Operador inválido!\n");
                    exit(EXIT_FAILURE);
            }
            push(&stack, result);
        }

        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main() {
    char expression[100];

    printf("Digite a expressão a ser calculada: ");
    fgets(expression, sizeof(expression), stdin);

    double result = evaluateExpression(expression);
    printf("Resultado: %.2f\n", result);

    return 0;
}
