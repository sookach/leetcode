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
  int shortestBridge(vector<vector<int>> &grid) {
    array<bitset<100>, 100> a;
    deque<pair<int, int>> q;
    for (int i = 0; i != size(grid); ++i) {
      for (int j = 0; j != size(grid.front()); ++j) {
        if (grid[i][j] == 0)
          continue;
        recursive([&](auto &&self, auto i, auto j) -> void {
          if (clamp<int>(i, 0, size(grid) - 1) != i ||
              clamp<int>(j, 0, size(grid.front()) - 1) != j || grid[i][j] != 1)
            return;

          q.emplace_back(i, j);
          a[i].set(j);
          grid[i][j] = 2;

          self(i + 1, j);
          self(i - 1, j);
          self(i, j + 1);
          self(i, j - 1);
        })(i, j);
        goto solve;
      }
    }

  solve:
    for (int x = 0;; ++x) {
      for (int n = size(q); n != 0; --n) {
        auto [i, j] = q.front();
        q.pop_front();

        if (grid[i][j] == 1)
          return x - 1;

        if (i != size(grid) - 1 && !a[i + 1].test(j)) {
          a[i + 1].set(j);
          q.emplace_back(i + 1, j);
        }

        if (i != 0 && !a[i - 1].test(j)) {
          a[i - 1].set(j);
          q.emplace_back(i - 1, j);
        }

        if (j != size(grid.front()) - 1 && !a[i].test(j + 1)) {
          a[i].set(j + 1);
          q.emplace_back(i, j + 1);
        }

        if (j != 0 && !a[i].test(j - 1)) {
          a[i].set(j - 1);
          q.emplace_back(i, j - 1);
        }
      }
    }

    return -1;
  }
};
