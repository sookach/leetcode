class Solution {
public:
  int countServers(vector<vector<int>> &grid) {
    array<int, 250> a1 = {}, a2 = {};
    int n = 0;

    for (int i = 0; i != size(grid); ++i) {
      for (int j = 0; j != size(grid.front()); ++j) {
        a1[i] += grid[i][j];
        a2[j] += grid[i][j];
      }
    }

    for (int i = 0; i != size(grid); ++i)
      for (int j = 0; j != size(grid.front()); ++j)
        n += static_cast<int>(grid[i][j] == 1 && (a1[i] != 1 || a2[j] != 1));

    return n;
  }
};
