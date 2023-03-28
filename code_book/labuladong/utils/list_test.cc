
#include "list.h"

int main() {
  ListNode *head = nullptr;
  for (int i = 10; i > 0; i--) {
    head = new ListNode(i, head);
  }
  printList(head);
}