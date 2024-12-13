class Solution {
public:
  int minSwaps(vector<vector<int>> &grid) {
    int n = 0;

    for (int i = 0; i != size(grid) - 1; ++i) {
      int j = i;
      for (; j != size(grid); ++j)
        if (find(crbegin(grid[j]), crend(grid[j]), 1) - crbegin(grid[j]) >=
            size(grid) - i - 1)
          break;

      if (j == size(grid))
        return -1;

      n += j - i;
      for (; j != i; --j)
        swap(grid[j], grid[j - 1]);
    }

    return n;
  }
};
