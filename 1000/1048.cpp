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
  int longestStrChain(vector<string> &words) {
    array<vector<int>, 1'000> a;
    bitset<1'000> b;
    auto n = numeric_limits<int>::min();

    for (int i = 0; i != size(words); ++i) {
      for (int j = 0; j != size(words); ++j) {
        if (size(words[i]) != size(words[j]) - 1)
          continue;

        int k = 0;
        for (; k != size(words[i]) && words[i][k] == words[j][k]; ++k)
          ;

        if (words[i].substr(0, k) + words[j][k] + words[i].substr(k) ==
            words[j])
          a[i].push_back(j);
      }
    }

    for (int i = 0; i != size(words); ++i) {
      b.reset();
      n = max(n, recursive([&](auto &&self, auto i) -> int {
                if (b.test(i))
                  return 0;

                b.set(i);
                int n = 0;

                for (auto &&x : a[i])
                  n = max(n, self(x));

                return n + 1;
              })(i));
    }

    return n;
  }
};
