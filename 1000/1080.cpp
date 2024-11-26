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
  TreeNode *sufficientSubset(TreeNode *root, int limit) {

    return recursive([&](auto &&self, auto x, auto y) -> bool {
      y += x->val;

      if (x->left == nullptr && x->right == nullptr)
        return y < limit;

      bool b1 = x->left == nullptr || self(x->left, y),
           b2 = x->right == nullptr || self(x->right, y);

      if (b1)
        x->left = nullptr;

      if (b2)
        x->right = nullptr;

      return b1 && b2;
    })(root, 0)
               ? nullptr
               : root;
  }
};
