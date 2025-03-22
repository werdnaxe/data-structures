#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 10

// Stack struct
struct stack {
  int arr[MAXSIZE];
  int top;
  int count;
};

void initialize_stack(struct stack* s) {

  s->top = 0;
  s->count = 0;

  for (int i = 0; i < MAXSIZE; i ++) {
    s->arr[i] = INT_MIN;
  }
}

void push(struct stack* s, int value) {

  if (s->count == MAXSIZE) {
    fprintf(stderr, "Stack is full\n");
    exit(EXIT_FAILURE);
  }
  
  if (!s->count) {
    s->arr[s->top] = value;
  } else {
    s->arr[s->top + 1] = value;
    s->top++;
  }
  s->count++;
}

int pop(struct stack* s) {

  if (!s->count) {
    fprintf(stderr, "Stack is empty\n");
    exit(EXIT_FAILURE);
  }

  int value = 0;
  if (s->count > 1) {
    value = s->arr[s->top];
    s->arr[s->top--] = INT_MIN;
  } else {
    value = s->arr[s->top];
    s->arr[s->top] = INT_MIN;
  }
  s->count--;

  return value;
}

int peek(struct stack* s) {

  if (!s->count) {
    printf("Stack is empty\n");
    return INT_MIN;
  }

  return s->arr[s->top];
}

void clear(struct stack* s) {

  initialize_stack(s);
}

void print_stack(struct stack* s) {

  for (int i = 0; i < MAXSIZE; i++) {
    printf("[%d]\n", s->arr[i]);
  }
}

int main() {

  struct stack stack;
  initialize_stack(&stack);
  push(&stack, 68);
  push(&stack, 47);
  push(&stack, 9);

  print_stack(&stack);   // 68 47 9 + 7 INT_MINs
  printf("\n");

  pop(&stack);   
  pop(&stack);   

  print_stack(&stack);   // 68 + 9 INT_MINs
  printf("\n");

  int num = peek(&stack);
  printf("%d\n\n", num);   // 68

  clear(&stack);

  print_stack(&stack);   // empty stack (all INT_MINs)
  
  return 0;
}
