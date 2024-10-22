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
  long long kthLargestLevelSum(TreeNode *root, int k) {
    array<long long, 100'000> a = {};
    priority_queue<long long> q;
    int n = 0;

    recursive([&](auto &&self, TreeNode *t, int i) -> void {
      if (t == nullptr)
        return;

      n = max(n, i);

      a[i] += t->val;
      self(t->left, i + 1);
      self(t->right, i + 1);
    })(root, 0);

    for (int i = 0; i <= n; ++i) {
      q.push(-a[i]);
      if (size(q) > k)
        q.pop();
    }

    return size(q) == k ? -q.top() : -1;
  }
};
