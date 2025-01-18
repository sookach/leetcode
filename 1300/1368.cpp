class Solution {
public:
  int minCost(vector<vector<int>> &grid) {
    priority_queue<tuple<int, int, int>> q;
    array<array<int, 100>, 100> a;

    for (auto &&x : a)
      ranges::fill(x, numeric_limits<int>::min());

    q.emplace(0, 0, 0);

    for (;;) {
      auto [x, i, j] = q.top();
      q.pop();

      if (i == size(grid) - 1 && j == size(grid.front()) - 1)
        return -x;

      if (a[i][j] >= x)
        continue;

      a[i][j] = x;

      if (i != 0)
        q.emplace(x - static_cast<int>(grid[i][j] != 4), i - 1, j);

      if (i != size(grid) - 1)
        q.emplace(x - static_cast<int>(grid[i][j] != 3), i + 1, j);

      if (j != 0)
        q.emplace(x - static_cast<int>(grid[i][j] != 2), i, j - 1);

      if (j != size(grid.front()) - 1)
        q.emplace(x - static_cast<int>(grid[i][j] != 1), i, j + 1);
    }

    return -1;
  }
};
