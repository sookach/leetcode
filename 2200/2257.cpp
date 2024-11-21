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
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    unordered_set<string> u1, u2, u3;
    array<bitset<100'000>, 100'000> a1 = {}, a2 = {}, a3 = {};
    recursive f = [&](auto &&self, auto i, auto j, auto k) -> void {
      if (clamp(i, 0, m - 1) != i || clamp(j, 0, n - 1) != j ||
          u1.contains(to_string(i) + ' ' + to_string(j)) ||
          u2.contains(to_string(i) + ' ' + to_string(j)))
        return;

      u3.insert(to_string(i) + ' ' + to_string(j));

      switch (k) {
      default:
        return self(i - 1, j, k);
      case 1:
        return self(i + 1, j, k);
      case 2:
        return self(i, j - 1, k);
      case 3:
        return self(i, j + 1, k);
      }
    };

    for (auto &&x : walls)
      u1.insert(to_string(x.front()) + ' ' + to_string(x.back()));

    for (auto &&x : guards)
      u2.insert(to_string(x.front()) + ' ' + to_string(x.back()));

    for (auto &&x : guards) {
      f(x.front() - 1, x.back(), 0);
      f(x.front() + 1, x.back(), 1);
      f(x.front(), x.back() - 1, 2);
      f(x.front(), x.back() + 1, 3);
    }

    return m * n - size(u1) - size(u2) - size(u3);
  }
};
