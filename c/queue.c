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

  if (!q->count) {
    q->arr[q->tail] = num;
  } else {
    q->arr[q->tail + 1] = num;
    q->tail++;
  }
  q->count++;
}

int dequeue(struct queue* q) {

  if (!q->count) {
    fprintf(stderr, "Queue is empty\n");
    exit(EXIT_FAILURE);
  }

  int num;
  if (q->count == 1) {
    num = q->arr[q->head];
    q->arr[q->head] = INT_MIN;
  } else {
    num = q->arr[q->head];
    q->arr[q->head++] = INT_MIN;
  }
  q->count--;

  return num;
}

int peek(struct queue* q) {

  if (!q->count) {
    fprintf(stderr, "Queue is empty\n");
    exit(EXIT_FAILURE);
  }

  int num = q->arr[q->head];
  return num;
}

void clear(struct queue* q) {

  initialize_queue(q);
}

void align(struct queue* q) {

  if (!q->count || q->count == MAXSIZE) {
    printf("Queue already aligned\n");
    return;
  }

  int i = q->head;
  q->head = 0;
  int start = q->head;
  while (start != q->tail) {
    q->arr[start++] = q->arr[i++];
  }
  q->tail = q->count - 1;
}

void print_queue(struct queue* q) {

  if (!q->count) {
    printf("Queue is empty\n");
    return;
  }
  
  for (int i = q->head; i <= q->tail; i++) {
    printf("[%d]", q->arr[i]);
  }
}

int main() {

  struct queue queue;
  initialize_queue(&queue);
  
  enqueue(&queue, 1);
  enqueue(&queue, 7);
  enqueue(&queue, 47);
  enqueue(&queue, 11);

  print_queue(&queue);   // [1][7][47][11]
  printf("   Count = %d\n", queue.count);   // 4

  dequeue(&queue);
  dequeue(&queue);

  for (int i = 0; i <= queue.tail; i++) {   // [INT_MIN][INT_MIN][47][11]
    printf("[%d]", queue.arr[i]);
  }
  printf("   Count = %d\n", queue.count);   // 2

  align(&queue);
  
  for (int i = 0; i <= queue.tail; i++) {   // [47][11]
    printf("[%d]", queue.arr[i]);
  }
  printf("   Count = %d\n", queue.count);   // 2

  int num = peek(&queue);
  printf("The first element of the queue is %d\n", num);   // 47

  clear(&queue);

  print_queue(&queue);   // emptpy queue
  printf("   Count = %d\n", queue.count);   // 0

  return 0;
}
