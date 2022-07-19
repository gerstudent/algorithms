#include <bits/stdc++.h>
using namespace std;

struct queueNode {
  int data;
  queueNode* next;

  queueNode(int d) {
    next = NULL;
    data = d;
  }
};

struct Queue {
  queueNode *front, *back;
  Queue() { front = back = NULL; }

  void enqueue(int elem) {
    queueNode* node = new queueNode(elem);
    if (back == NULL) {
      cout << "empty" << '\n';
      front = back = node;
      return;
    }
    back->next = node;
    back = node;
  }

  void dequeue() {
    if (front == NULL) {
      cout << "empty" << '\n';
      return;
    }
    queueNode* node = front;
    front = front->next;
    if (front == NULL) {
      back = NULL;
    }
    delete[] node;
  }
};

int main() {
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);

  q.dequeue();
  q.dequeue();

  cout << "front: " << q.front->data << '\n';
  cout << "back: " << q.back->data << '\n';
  return 0;
}