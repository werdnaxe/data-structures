#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 10

// Queue struct
struct queue {
  int arr[MAXSIZE];
  int head;
  int tail;
  int count;
};

void initialize_queue(struct queue* q) {
  
  q->head = 0;
  q->tail = 0;
  q->count = 0;

  for (int i = 0; i < MAXSIZE; i++) {
    q->arr[i] = INT_MIN;
  }
}

void enqueue(struct queue* q, int num) {
  
  if (q->count == MAXSIZE) {
    fprintf(stderr, "Queue is full\n");
    exit(EXIT_FAILURE);
  }
  
  q->arr[q->tail++] = num;
  q->count++;  
}

int dequeue(struct queue* q) {

  if (!q->count) {
    fprintf(stderr, "Queue is empty\n");
    exit(EXIT_FAILURE);
  }

  q->arr[q->head++] = INT_MIN;
  q->count--;
}

int peek(struct queue* q) {

  if (!q->count) {
    fprintf(stderr, "Queue is empty\n");
    exit(EXIT_FAILURE);
  }

  int num = q->arr[q->head];
  return num;
}

int main() {

  struct queue queue;
  initialize_queue(&queue);
  
  enqueue(&queue, 1);
  enqueue(&queue, 7);
  enqueue(&queue, 47);
  enqueue(&queue, 11);

  for (int i = 0; i < queue.count; i++) {
    printf("[%d]", queue.arr[i]);
  }
  printf("   Count = %d\n", queue.count);

  int num1 = dequeue(&queue);
  printf("Num 1: %d\n", num1);
  int num2 = dequeue(&queue);
  printf("Num 2: %d\n", num2);

  for (int i = queue.head; i < queue.tail; i++) {
    printf("[%d]", queue.arr[i]);
  }
    printf("   Count = %d\n", queue.count);

  return 0;
}
