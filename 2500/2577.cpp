class Solution {
public:
  int minimumTime(vector<vector<int>> &grid) {
    array<bitset<1'000>, 1'000> a;
    priority_queue<tuple<int, int, int>> q;
    auto f = [&](auto &&i, auto &&j, auto &&x) {
      if (clamp<int>(i, 0, size(grid) - 1) != i ||
          clamp<int>(j, 0, size(grid.front()) - 1) != j || a[i].test(j))
        return;

      if (abs(x) >= grid[i][j]) {
        q.emplace(x, i, j);
        return;
      }

      q.emplace(-grid[i][j] - (grid[i][j] - abs(x)) % 2, i, j);
    };

    if (grid.front()[1] > 1 && grid[1].front() > 1)
      return -1;

    q.emplace(0, 0, 0);

    for (;;) {
      auto [x, i, j] = q.top();
      q.pop();

      if (a[i].test(j))
        continue;

      a[i].set(j);

      if (i == size(grid) - 1 && j == size(grid.front()) - 1)
        return -x;

      --x;

      f(i - 1, j, x);
      f(i + 1, j, x);
      f(i, j - 1, x);
      f(i, j + 1, x);
    }
  }
};
