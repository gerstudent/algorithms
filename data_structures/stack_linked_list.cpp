#include <bits/stdc++.h>
using namespace std;

struct stackNode {
  int data;
  stackNode* next;
};

stackNode* newNode(int data) {
  stackNode* stackNode = new struct stackNode();
  stackNode->data = data;
  stackNode->next = NULL;
  return stackNode;
}

int empty(stackNode* st) { return !st; }

void push(stackNode** st, int data) {
  stackNode* stackNode = newNode(data);
  stackNode->next = *st;
  *st = stackNode;
  cout << data << " pushed\n";
}

int pop(stackNode** st) {
  if (empty(*st)) {
    return INT_MIN;
  }
  stackNode* temp = *st;
  *st = (*st)->next;
  int popped = temp->data;

  delete[] temp;
  return popped;
}

int top(stackNode* st) {
  if (empty(st)) {
    return -1;
  }
  return st->data;
}

int main() {
  stackNode* st = NULL;

  push(&st, 1);
  push(&st, 2);
  push(&st, 3);
  push(&st, 4);

  cout << pop(&st) << " was removed from stack\n";

  cout << "Top element: " << top(st) << '\n';

  while (!empty(st)) {
    cout << top(st) << ' ';
    pop(&st);
  }
  delete[] st;
  return 0;
}