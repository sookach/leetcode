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
  vector<vector<string>> printTree(TreeNode *root) {
    auto h = recursive([](auto &&self, TreeNode *t, int i) -> int {
      if (t == nullptr)
        return i - 1;
      return max(self(t->left, i + 1), self(t->right, i + 1));
    })(root, 0);

    vector v(h + 1, vector<string>(pow(2, h + 1) - 1));

    recursive([&](auto &&self, TreeNode *t, int i, int j) -> void {
      if (t == nullptr)
        return;

      v[i][j] = to_string(t->val);

      self(t->left, i + 1, j - pow(2, h - i - 1));
      self(t->right, i + 1, j + pow(2, h - i - 1));
    })(root, 0, (size(v.front()) - 1) / 2);

    return v;
  }
};
