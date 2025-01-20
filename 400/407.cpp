class Solution {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    priority_queue<tuple<int, int, int>> q;
    int n = 0;

    for (int j = 0; j != size(heightMap.front()); ++j) {
      q.emplace(-heightMap.front()[j], 0, j);
      q.emplace(-heightMap.back()[j], size(heightMap) - 1, j);
    }

    for (int i = 1; i < size(heightMap) - 1; ++i) {
      q.emplace(-heightMap[i].front(), i, 0);
      q.emplace(-heightMap[i].back(), i, size(heightMap.front()) - 1);
    }

    for (int x = 0; !empty(q);) {
      auto [y, i, j] = q.top();
      q.pop();

      if (exchange(heightMap[i][j], -1) == -1)
        continue;

      x = max(x, -y);
      n += x + y;

      if (i != 0)
        q.emplace(-heightMap[i - 1][j], i - 1, j);

      if (i != size(heightMap) - 1)
        q.emplace(-heightMap[i + 1][j], i + 1, j);

      if (j != 0)
        q.emplace(-heightMap[i][j - 1], i, j - 1);

      if (j != size(heightMap.front()) - 1)
        q.emplace(-heightMap[i][j + 1], i, j + 1);
    }

    return n;
  }
};
