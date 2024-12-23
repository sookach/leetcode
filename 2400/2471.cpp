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
  int minimumOperations(TreeNode *root) {
    vector<TreeNode *> v1, v2, v3;
    array<int, 100'001> a = {};
    int n = 0;

    v1.push_back(root);

    for (; !empty(v1);) {
      bitset<100'000> b;

      for (auto &&x : v1) {
        if (x->left != nullptr)
          v2.push_back(x->left);
        if (x->right != nullptr)
          v2.push_back(x->right);
      }

      v3 = v1;

      ranges::sort(v3, {}, &TreeNode::val);

      for (int i = 0; i != size(v3); ++i)
        a[v3[i]->val] = i;

      for (int i = 0; i != size(v1); ++i)
        if (!b.test(i))
          n += recursive([&](auto &&self, int i) -> int {
                 if (b.test(i))
                   return 0;
                 b.set(i);
                 return self(a[v1[i]->val]) + 1;
               })(i) -
               1;

      v1 = std::move(v2);
      v2.clear();
      v3.clear();
    }

    return n;
  }
};
