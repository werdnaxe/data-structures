#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 10

typedef struct circular_buffer {
  int arr[MAXSIZE];
  int read;
  int write;
  int size;
} cbuf;

void init_buf(cbuf* cbuf) {

  cbuf->read = 0;
  cbuf->write = 0;
  cbuf->size = 0;
  
  for (int i = 0; i < MAXSIZE; i++) {
    cbuf->arr[i] = INT_MIN;
  }
}

void push(cbuf* cbuf, int value) {

  if (cbuf->size > 10) {
    printf("Overwriting\n");
  }
  
  cbuf->write = cbuf->write % MAXSIZE;
  cbuf->arr[cbuf->write++] = value;
  cbuf->size++;

}

int pop(cbuf* cbuf) {

  if (!cbuf->size) {
    fprintf(stderr, "Cannot read from empty buf\n");
    exit(EXIT_FAILURE);
  }

  cbuf->read = cbuf->read % MAXSIZE;
  int value = cbuf->arr[cbuf->read];
  cbuf->arr[cbuf->read++] = INT_MIN;
  cbuf->size--;
  
  return value;

}

int peek(cbuf* cbuf) {

  return cbuf->arr[cbuf->read];

}

void print_cbuf(cbuf* cbuf) {

  for (int i = cbuf->read; i < cbuf->write; i++) {
    printf("[%d]", cbuf->arr[i]);
  }
  printf("\n\n");
}

int main() {

  cbuf cbuf;
  init_buf(&cbuf);

  // Populate buffer
  for (int i = 0; i < MAXSIZE; i++) {
    push(&cbuf, i);
  }
  print_cbuf(&cbuf);

  push(&cbuf, 10);
  push(&cbuf, 11);
  push(&cbuf, 12);
  push(&cbuf, 13);

  print_cbuf(&cbuf);

  return 0;

}
