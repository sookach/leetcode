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
  int maxUniqueSplit(string s) {
    unordered_set<string> u;
    return recursive([&](auto &&self, int i) -> int {
      if (i == size(s))
        return 0;

      int n = 0;

      for (int j = i + 1; j <= size(s); ++j) {
        if (!u.contains(s.substr(i, j - i))) {
          u.insert(s.substr(i, j - i));
          n = max(n, self(j) + 1);
          u.erase(s.substr(i, j - i));
        }
      }

      return n;
    })(0);
  }
};
