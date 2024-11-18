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
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    vector<pair<TreeNode *, int>> v;
    int n = 0;

    recursive([&](auto &&self, auto &&t, auto &&x) -> void {
      if (t == nullptr)
        return;

      self(t->left, x + 1);
      n = max(n, x);
      v.emplace_back(t, x);
      self(t->right, x + 1);
    })(root, 0);

    return min_element(find_if(cbegin(v), cend(v),
                               [n](auto &&x) { return x.second == n; }),
                       find_if(crbegin(v), crend(v),
                               [n](auto &&x) { return x.second == n; })
                           .base(),
                       [](auto &&x, auto &&y) { return x.second < y.second; })
        ->first;
  }
};
