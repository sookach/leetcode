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
  vector<int> largestValues(TreeNode *root) {
    vector<int> v;

    recursive([&](auto &&self, TreeNode *t, int n) -> void {
      if (t == nullptr)
        return;

      if (size(v) <= n)
        v.resize(n + 1, numeric_limits<int>::min());

      v[n] = max(v[n], t->val);
      self(t->left, n + 1);
      self(t->right, n + 1);
    })(root, 0);

    return v;
  }
};
