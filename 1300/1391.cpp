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
  bool hasValidPath(vector<vector<int>> &grid) {
    array<bitset<300>, 300> a1;
    array<array<int, 6>, 6> a2 = {};

    return recursive([&](auto &&self, int i, int j) -> bool {
      if (a1[i].test(j))
        return false;
      a1[i].set(j);

      if (i == size(grid) - 1 && j == size(grid.front()) - 1)
        return true;

      if (i != 0) {
        switch (grid[i][j]) {
        default:
          break;
        case 2:
        case 5:
        case 6:
          switch (grid[i - 1][j]) {
          default:
            break;
          case 2:
          case 3:
          case 4:
            if (self(i - 1, j))
              return true;
          }
          break;
        }
      }

      if (i != size(grid) - 1) {
        switch (grid[i][j]) {
        default:
          break;
        case 2:
        case 3:
        case 4:
          switch (grid[i + 1][j]) {
          default:
            break;
          case 2:
          case 5:
          case 6:
            if (self(i + 1, j))
              return true;
          }
          break;
        }
      }

      if (j != 0) {
        switch (grid[i][j]) {
        default:
          break;
        case 1:
        case 3:
        case 5:
          switch (grid[i][j - 1]) {
          default:
            break;
          case 1:
          case 4:
          case 6:
            if (self(i, j - 1))
              return true;
          }
          break;
        }
      }

      if (j != size(grid.front()) - 1) {
        switch (grid[i][j]) {
        default:
          break;
        case 1:
        case 4:
        case 6:
          switch (grid[i][j + 1]) {
          default:
            break;
          case 1:
          case 3:
          case 5:
            if (self(i, j + 1))
              return true;
          }
          break;
        }
      }

      return false;
    })(0, 0);
  }
};
