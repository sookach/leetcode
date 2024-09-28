class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *l = new ListNode;
    ListNode *x = l;
    int y = 0;

    for (; l1 != nullptr && l2 != nullptr; l1 = l1->next, l2 = l2->next) {
      y += l1->val + l2->val;
      x->next = new ListNode(y % 10);
      y /= 10;
      x = x->next;
    }

    for (; l1 != nullptr; l1 = l1->next) {
      y += l1->val;
      x->next = new ListNode(y % 10);
      y /= 10;
      x = x->next;
    }

    for (; l2 != nullptr; l2 = l2->next) {
      y += l2->val;
      x->next = new ListNode(y % 10);
      y /= 10;
      x = x->next;
    }

    if (y != 0)
      x->next = new ListNode(y);

    return l->next;
  }
};

