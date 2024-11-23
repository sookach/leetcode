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
  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col,
                                  int color) {
    array<array<int, 50>, 50> a = {};

    for (auto &&x : a)
      ranges::fill(x, -1);

    recursive([&](auto &&self, auto i, auto j) -> bool {
      if (clamp<int>(i, 0, size(grid) - 1) != i ||
          clamp<int>(j, 0, size(grid.front()) - 1) != j)
        return false;

      if (a[i][j] != -1)
        return a[i][j];

      a[i][j] = grid[i][j] == grid[row][col];

      if (!a[i][j])
        return false;

      bool b = self(i + 1, j);
      b &= self(i - 1, j);
      b &= self(i, j + 1);
      b &= self(i, j - 1);

      if (!b)
        grid[i][j] = color;

      return true;
    })(row, col);

    return grid;
  }
};
