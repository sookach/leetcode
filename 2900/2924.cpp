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
  int findChampion(int n, vector<vector<int>> &edges) {
    bitset<100> b1, b2;
    array<vector<int>, 100> a;

    for (auto &&x : edges)
      a[x.front()].push_back(x.back());

    for (int i = 0; i != n; ++i) {
      recursive([&](auto &&self, auto &&i) -> void {
        if (b1.test(i))
          return;

        b1.set(i);

        for (auto &&x : a[i]) {
          b2.set(x);
          self(x);
        }
      })(i);
    }

    if (n - b2.count() != 1)
      return -1;

    for (int i = 0; i != n; ++i)
      if (!b2.test(i))
        return i;

    return -1;
  }
};
