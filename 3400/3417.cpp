class Solution {
public:
  vector<int> zigzagTraversal(vector<vector<int>> &grid) {
    vector<int> v;

    for (int i = 0, k = 0; i != size(grid); ++i)
      for (int j = i % 2 == 0 ? 0 : size(grid.front()) - 1;
           j >= 0 && j < size(grid.front()); j += i % 2 == 0 ? 1 : -1)
        if ((k = 1 - k) == 1)
          v.push_back(grid[i][j]);

    return v;
  }
};
