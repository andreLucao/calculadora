#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

int is_operator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
  switch (ch) {
    case '*':
    case '/':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return 0;
  }
}

int is_digit(char ch) {
  returnisdigit(ch);
}

char pop(char* stack) {
  static int top = -1;
  if (top == -1) {
    printf("Pilha vazia\n");
    return '\0';
  }
  return stack[top--];
}

void push(char* stack, char item) {
  static int top = -1;
  if (top == MAX_SIZE - 1) {
    printf("Pilha cheia\n");
    return;
  }
  stack[++top] = item;
}

void shunting_yard(char* infix, char* postfix) {
  char stack[MAX_SIZE];
  int i = 0, j = 0;
  char ch;

  while ((ch = infix[i++]) != '\0') {
    if (is_digit(ch)) {
      postfix[j++] = ch;
    } else if (ch == '(') {
      push(stack, ch);
    } else if (ch == ')') {
      while ((ch = pop(stack)) != '(' && ch != '\0') {
        postfix[j++] = ch;
      }
      if (ch == '\0') {
        printf("Expressão inválida\n");
        return;
      }
    } else if (is_operator(ch)) {
      while (stack[top] != '\0' && precedence(stack[top]) >= precedence(ch)) {
        postfix[j++] = pop(stack);
      }
      push(stack, ch);
    } else {
      printf("Caractere inválido: %c\n", ch);
      return;
    }
  }

  while (stack[top] != '\0') {
    postfix[j++] = pop(stack);
  }
  postfix[j] = '\0';
}
