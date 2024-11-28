class Solution {
public:
  int minimumObstacles(vector<vector<int>> &grid) {
    vector v(size(grid),
             vector<int>(size(grid.front()), numeric_limits<int>::min()));
    priority_queue<tuple<int, int, int>> q;

    q.emplace(0, 0, 0);

    for (;;) {
      auto [x, i, j] = q.top();
      q.pop();

      if (i == size(grid) - 1 && j == size(grid.front()) - 1)
        return -x;

      if (v[i][j] > x)
        continue;

      v[i][j] = x + 1;
      x -= grid[i][j];

      if (i != 0 && v[i - 1][j] < x) {
        v[i - 1][j] = x;
        q.emplace(x, i - 1, j);
      }

      if (i != size(grid) - 1 && v[i + 1][j] < x) {
        v[i + 1][j] = x;
        q.emplace(x, i + 1, j);
      }

      if (j != 0 && v[i][j - 1] < x) {
        v[i][j - 1] = x;
        q.emplace(x, i, j - 1);
      }

      if (j != size(grid.front()) - 1 && v[i][j + 1] < x) {
        v[i][j + 1] = x;
        q.emplace(x, i, j + 1);
      }
    }
  }
};
