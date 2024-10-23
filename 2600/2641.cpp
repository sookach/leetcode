class Solution {
public:
  TreeNode *replaceValueInTree(TreeNode *root) {
    deque q = {root};
    root->val = 0;

    for (int x = 0; !empty(q);) {
      int y = 0;
      for (auto n = size(q); n != 0; --n) {
        auto t = q.front();
        q.pop_front();
        t->val += x;

        int i = t->left == nullptr ? 0 : t->left->val,
            j = t->right == nullptr ? 0 : t->right->val;

        y += i + j;

        if (t->left != nullptr) {
          t->left->val = -i - j;
          q.push_back(t->left);
        }

        if (t->right != nullptr) {
          t->right->val = -i - j;
          q.push_back(t->right);
        }
      }
      x = y;
    }

    return root;
  }
};
