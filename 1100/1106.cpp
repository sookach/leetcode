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
  bool parseBoolExpr(string expression) {
    int i = 0;
    return recursive([&](auto &&self) -> bool {
      switch (expression[i++]) {
      case 't':
        return true;
      case 'f':
        return false;
      case '!': {
        ++i;
        bool b = self();
        ++i;
        return !b;
      }
      case '&': {
        ++i;
        bool b = self();
        for (; expression[i] == ',';) {
          ++i;
          b &= self();
        }
        ++i;
        return b;
      }
      case '|': {
        ++i;
        bool b = self();
        for (; expression[i] == ',';) {
          ++i;
          b |= self();
        }
        ++i;
        return b;
      }
      default:
        return false;
      }
    })();
  }
};
