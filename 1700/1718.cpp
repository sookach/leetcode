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
  vector<int> constructDistancedSequence(int n) {
    vector<int> v((n - 1) * 2 + 1);
    bitset<21> b;

    recursive([&](auto &&self, int i) -> bool {
      if (i == size(v))
        return true;

      if (v[i] != 0)
        return self(i + 1);

      for (int j = n; j != 1; --j) {
        if (b.test(j) || i + j >= size(v) || v[i + j] != 0)
          continue;

        b.set(j);
        v[i] = v[i + j] = j;
        if (self(i + 1))
          return true;
        v[i] = v[i + j] = 0;
        b.reset(j);
      }

      if (!b.test(1)) {
        b.set(1);
        v[i] = 1;
        if (self(i + 1))
          return true;
        v[i] = 0;
        b.reset(1);
      }

      return false;
    })(0);

    return v;
  }
};
