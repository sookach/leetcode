class Solution {
public:
  int minTimeToReach(vector<vector<int>> &moveTime) {
    priority_queue<tuple<int, int, int, int>> q;
    array<array<array<int, 2>, 750>, 750> a = {};

    for (auto &&x : a)
      for (auto &&y : x)
        ranges::fill(y, numeric_limits<int>::min());

    q.emplace(0, 0, 0, 1);

    for (;;) {
      auto [t, i, j, x] = q.top();
      q.pop();

      if (i == size(moveTime) - 1 && j == size(moveTime.front()) - 1)
        return -t;

      if (t < a[i][j][x])
        continue;

      a[i][j][x] = t;

      if (i != 0 && min(-moveTime[i - 1][j], t) - 2 + x > a[i - 1][j][1 - x]) {
        a[i - 1][j][1 - x] = min(-moveTime[i - 1][j], t) - 2 + x;
        q.emplace(a[i - 1][j][1 - x], i - 1, j, 1 - x);
      }

      if (i != size(moveTime) - 1 &&
          min(-moveTime[i + 1][j], t) - 2 + x > a[i + 1][j][1 - x]) {
        a[i + 1][j][1 - x] = min(-moveTime[i + 1][j], t) - 2 + x;
        q.emplace(a[i + 1][j][1 - x], i + 1, j, 1 - x);
      }

      if (j != 0 && min(-moveTime[i][j - 1], t) - 2 + x > a[i][j - 1][1 - x]) {
        a[i][j - 1][1 - x] = min(-moveTime[i][j - 1], t) - 2 + x;
        q.emplace(a[i][j - 1][1 - x], i, j - 1, 1 - x);
      }

      if (j != size(moveTime.front()) - 1 &&
          min(-moveTime[i][j + 1], t) - 2 + x > a[i][j + 1][1 - x]) {
        a[i][j + 1][1 - x] = min(-moveTime[i][j + 1], t) - 2 + x;
        q.emplace(a[i][j + 1][1 - x], i, j + 1, 1 - x);
      }
    }
  }
};
