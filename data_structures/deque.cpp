#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000;

struct Deque {
  int arr[MAXV], size, head, tail;
  Deque(int sz) {
    size = sz;
    head = size - 1;
    tail = size - 1;
  }

  bool empty() { return head == tail; }

  void pushHead(int val) { arr[--head] = val; }

  void pushBack(int val) { arr[tail++] = val; }

  int popFront() {
    if (empty()) {
      cout << "underflow\n";
      return -1;
    }
    return arr[head++];
  }

  int popBack() {
    if (empty()) {
      cout << "underflow\n";
      return -1;
    }
    return arr[--tail];
  }

  int getFront() {
    if (empty()) {
      cout << "underflow\n";
      return -1;
    }
    return arr[head];
  }

  int getBack() {
    if (empty()) {
      cout << "underflow\n";
      return -1;
    }
    return arr[tail - 1];
  }
};

int main() {
  Deque dq(4);

  dq.pushBack(1);
  dq.pushBack(2);
  dq.pushBack(3);
  dq.pushBack(4);
  // Deque: 1 2 3 4

  cout << "head: " << dq.getFront() << '\n';
  cout << "tail: " << dq.getBack() << '\n';

  dq.popBack();

  cout << "After deleting tail element\n";
  cout << "head: " << dq.getFront() << '\n';
  cout << "tail: " << dq.getBack() << '\n';

  dq.popFront();

  cout << "After deleting first element\n";
  cout << "head: " << dq.getFront() << '\n';
  cout << "tail: " << dq.getBack() << '\n';

  dq.popFront();
  dq.popFront();

  cout << dq.getBack();
  return 0;
}