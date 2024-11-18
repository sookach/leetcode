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
  int scoreOfParentheses(string s) {
    int i = 0, n = 0;

    for (; i != size(s);)
      n += recursive([&](auto &&self) -> int {
        int x = 0;
        for (; i != size(s) && s[i++] != ')';)
          x += max(2 * self(), 1);
        return x;
      })();

    return n;
  }
};
