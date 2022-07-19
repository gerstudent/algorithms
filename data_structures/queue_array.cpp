#include <bits/stdc++.h>
using namespace std;

struct Queue {
  unsigned int volume;
  int size, head, tail;
  int* arr;
};

Queue* createQueue(unsigned int volume) {
  Queue* queue = new Queue();
  queue->volume = volume;
  queue->head = queue->size = 0;

  queue->tail = volume - 1;
  queue->arr = new int[queue->volume];
  return queue;
}

bool overflow(Queue* queue) {
  return ((unsigned int)queue->size == queue->volume);
}

bool empty(Queue* queue) { return (queue->size == 0); }

int enqueue(Queue* queue, int val) {
  if (overflow(queue)) {
    cout << "overflow" << '\n';
    return -1;
  }
  queue->tail = (queue->tail + 1) % queue->volume;
  queue->arr[queue->tail] = val;
  queue->size = queue->size + 1;
  return val;
}

int dequeue(Queue* queue) {
  if (empty(queue)) {
    cout << "underflow" << '\n';
    return -1;
  }
  int val = queue->arr[queue->head];
  queue->head = (queue->head + 1) % queue->volume;
  queue->size = queue->size - 1;
  return val;
}

int getFront(Queue* queue) {
  if (empty(queue)) {
    cout << "underflow" << '\n';
    return -1;
  }
  return queue->arr[queue->head];
}

int getBack(Queue* queue) {
  if (empty(queue)) {
    cout << "underflow" << '\n';
    return -1;
  }
  return queue->arr[queue->tail];
}

int main() {
  Queue* queue = createQueue(4);

  cout << enqueue(queue, 1) << " enqueued\n";
  cout << enqueue(queue, 2) << " enqueued\n";
  cout << enqueue(queue, 3) << " enqueued\n";
  cout << enqueue(queue, 4) << " enqueued\n";

  cout << "head: " << getFront(queue) << '\n';
  cout << "tail: " << getBack(queue) << '\n';
  cout << dequeue(queue) << " dequeued\n";
  cout << "head: " << getFront(queue) << '\n';

  delete[] queue;
  return 0;
}