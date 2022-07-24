#include <bits/stdc++.h>
using namespace std;

const int MAXV = 100500;

struct priorityQueue {
  int val, pr;
};

priorityQueue arr[MAXV];
int sz = -1;

void enqueue(int val, int pr) {
  sz++;
  arr[sz].val = val;
  arr[sz].pr = pr;
}

int top() {
  int highPr = INT_MIN, idx = -1;

  for (int i = 0; i <= sz; i++) {
    if (highPr == arr[i].pr && idx > -1 && arr[idx].val < arr[i].val) {
      highPr = arr[i].pr;
      idx = i;
    } else if (highPr < arr[i].pr) {
      highPr = arr[i].pr;
      idx = i;
    }
  }
  return idx;
}

void dequeue() {
  int idx = top();

  for (int i = idx; i < sz; i++) {
    arr[i] = arr[i + 1];
  }
  sz--;
}

int main() {
  enqueue(1, 5);
  enqueue(2, 6);
  enqueue(3, 7);
  enqueue(4, 8);

  int idx = top();
  cout << arr[idx].val << '\n';

  dequeue();

  idx = top();
  cout << arr[idx].val << '\n';

  dequeue();

  idx = top();
  cout << arr[idx].val << '\n';
  return 0;
}