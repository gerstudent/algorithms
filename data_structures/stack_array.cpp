#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000;

struct Stack {
  int a[MAXV], head;
  Stack() { head = -1; }

  bool empty() { return (head < 0); }

  void push(int x) {
    if (head >= (MAXV - 1)) {
      cout << "stack overflow";
    } else {
      a[++head] = x;
      cout << x << " pushed\n";
    }
  }

  int pop() {
    if (head < 0) {
      cout << "stack underflow";
      return 0;
    } else {
      int x = a[head--];
      return x;
    }
  }

  int top() {
    if (head < 0) {
      cout << "stack is empty";
      return 0;
    } else {
      int x = a[head];
      return x;
    }
  }
};

int main() {
  Stack st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  cout << st.pop() << " was removed from stack\n";

  cout << "top element: " << st.top() << '\n';

  while (!st.empty()) {
    cout << st.top() << ' ';
    st.pop();
  }
  return 0;
}