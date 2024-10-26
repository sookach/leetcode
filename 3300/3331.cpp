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
  vector<int> findSubtreeSizes(vector<int> &parent, string s) {
    vector<int> v1(parent), v2(size(parent));

    for (int i = 1; i != size(parent); ++i) {
      auto p = recursive([&](auto &&self, int j) -> int {
        return j == -1 ? -1 : s[i] == s[j] ? j : self(parent[j]);
      })(parent[i]);

      if (p != -1)
        v1[i] = p;
    }

    for (int i = 0; i != size(parent); ++i)
      recursive([&](auto &&self, int i) -> void {
        if (i == -1)
          return;
        ++v2[i];
        self(v1[i]);
      })(i);

    return v2;
  }
};
