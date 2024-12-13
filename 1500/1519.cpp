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
  vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
    array<vector<int>, 100'000> a = {};
    bitset<100'000> b;
    vector<int> v(n);

    for (auto &&x : edges) {
      a[x.front()].push_back(x.back());
      a[x.back()].push_back(x.front());
    }

    recursive([&](auto &&self, int i) -> array<int, 26> {
      array<int, 26> a1 = {};

      b.set(i);

      for (auto &&x : a[i]) {
        if (b.test(x))
          continue;
        auto a2 = self(x);
        for (int i = 0; i != 26; ++i)
          a1[i] += a2[i];
      }

      v[i] = ++a1[labels[i] - 'a'];

      return a1;
    })(0);

    return v;
  }
};
