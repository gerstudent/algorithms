#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

void printList(Node* elem) {
  while (elem != NULL) {
    cout << elem->data << ' ';
    elem = elem->next;
  }
  cout << '\n';
}

void pushFront(Node** head, int new_data) {
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = *head;
  *head = new_node;
}

void insertAfter(Node* prev, int new_data) {
  if (prev == NULL) {
    cout << "Error: previous node can`t be NULL";
    return;
  }
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = prev->next;
  prev->next = new_node;
}

void pushBack(Node** head, int new_data) {
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = NULL;
  Node* end = *head;

  if (*head == NULL) {
    *head = new_node;
    return;
  }
  while (end->next != NULL) {
    end = end->next;
  }

  end->next = new_node;
  return;
}

void deleteNodeValue(Node** head, int val) {
  Node* prev = NULL;
  Node* temp = *head;

  if (temp != NULL && temp->data == val) {
    *head = temp->next;
    delete[] temp;
    return;
  } else {
    while (temp->data != val && temp != NULL) {
      prev = temp;
      temp = temp->next;
    }
    if (temp == NULL) {
      cout << "Error: element not found" << '\n';
      return;
    }
    prev->next = temp->next;
    delete[] temp;
  }
}

void deleteNodePosition(Node** head, int pos) {
  if (*head == NULL) {
    cout << "Error: list is empty" << '\n';
    return;
  }
  Node* temp = *head;

  if (pos == 0) {
    *head = temp->next;
    delete[] temp;
    return;
  }
  for (int i = 0; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
  }
  if (temp->next == NULL || temp == NULL) {
    cout << "Error: position is greater than list size" << '\n';
    return;
  }

  // Pointer to the next of deleted node
  Node* next_pos = temp->next->next;

  // Delete memory
  delete[] temp->next;

  // Unlick deleted node from list
  temp->next = next_pos;
}

void deleteList(Node** head) {
  Node* next = NULL;
  Node* cur = *head;
  while (cur != NULL) {
    next = cur->next;
    delete[] cur;
    cur = next;
  }
  *head = NULL;
}

int lengthList(Node* head) {
  int len = 0;
  Node* cur = head;
  while (cur != NULL) {
    len++;
    cur = cur->next;
  }
  return len;
}

void middleNode(Node* head) {
  int iterator = 0;
  Node* mid = head;

  while (head != NULL) {
    if (iterator & 1) {
      mid = mid->next;
    }
    ++iterator;
    head = head->next;
  }
  cout << "Middle node: " << mid->data << '\n';
}

void findNthNode(Node* head, int idx) {
  int iterator = 1;
  Node* cur = head;

  while (cur != NULL) {
    if (iterator == idx) {
      cout << idx << " element is: " << cur->data << '\n';
    }
    iterator++;
    cur = cur->next;
  }
}

int main() {
  Node* head = NULL;

  pushFront(&head, 3);
  pushFront(&head, 1);
  insertAfter(head, 2);
  pushBack(&head, 5);
  insertAfter(head->next->next, 4);

  printList(head);  // Output: 1 2 3 4 5
  cout << "Length: " << lengthList(head) << '\n';
  middleNode(head);
  findNthNode(head, 2);

  deleteNodeValue(&head, 1);     // After: 2 3 4 5
  deleteNodePosition(&head, 3);  // After: 2 3 4

  printList(head);  // Output: 2 3 4
  cout << "Length: " << lengthList(head) << '\n';
  middleNode(head);
  findNthNode(head, 2);

  deleteList(&head);
  return 0;
}
