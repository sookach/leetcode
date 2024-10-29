class Solution {
public:
  int maxMoves(vector<vector<int>> &grid) {
    array<bitset<1'000>, 1'000> a = {};
    int n = 0;

    for (auto &&x : a)
      x.set(0);

    for (int j = 1; j != size(grid.front()); ++j) {
      for (int i = 0; i != size(grid); ++i) {
        if (i != 0 && a[i - 1].test(j - 1) && grid[i][j] > grid[i - 1][j - 1] ||
            a[i].test(j - 1) && grid[i][j] > grid[i][j - 1] ||
            i != size(grid) - 1 && a[i + 1].test(j - 1) &&
                grid[i][j] > grid[i + 1][j - 1]) {
          a[i].set(j);
          n = j;
        }
      }
    }

    return n;
  }
};
