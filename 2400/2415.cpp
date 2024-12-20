template <typename T> struct recursive final {
  const T F;

  constexpr recursive(T &&F) : F(std::forward<T>(F)) {}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args &&...A) const noexcept {
    return F(std::cref(*this), std::forward<Args>(A)...);
  }
};

class Solution {
public:
  TreeNode *reverseOddLevels(TreeNode *root) {
    array<vector<TreeNode *>, 8'192> a = {};

    recursive([&](auto &&self, TreeNode *t, int x) -> void {
      if (t == nullptr)
        return;
      if (x % 2 == 1)
        a[x / 2].push_back(t);
      self(t->left, x + 1);
      self(t->right, x + 1);
    })(root, 0);

    for (auto &&x : a)
      for (int i = 0, j = size(x) - 1; i < j; ++i, --j)
        swap(x[i]->val, x[j]->val);

    return root;
  }
};
