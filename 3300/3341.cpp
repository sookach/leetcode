class Solution {
public:
  int minTimeToReach(vector<vector<int>> &moveTime) {
    priority_queue<tuple<int, int, int>> q;
    array<array<int, 50>, 50> a = {};

    for (auto &&x : a)
      ranges::fill(x, numeric_limits<int>::min());

    q.emplace(0, 0, 0);

    for (;;) {
      auto [t, i, j] = q.top();
      q.pop();

      if (i == size(moveTime) - 1 && j == size(moveTime.front()) - 1)
        return -t;

      if (t < a[i][j])
        continue;

      a[i][j] = t;

      if (i != 0 && min(-moveTime[i - 1][j], t) - 1 > a[i - 1][j]) {
        a[i - 1][j] = min(-moveTime[i - 1][j], t) - 1;
        q.emplace(a[i - 1][j], i - 1, j);
      }

      if (i != size(moveTime) - 1 &&
          min(-moveTime[i + 1][j], t) - 1 > a[i + 1][j]) {
        a[i + 1][j] = min(-moveTime[i + 1][j], t) - 1;
        q.emplace(a[i + 1][j], i + 1, j);
      }

      if (j != 0 && min(-moveTime[i][j - 1], t) - 1 > a[i][j - 1]) {
        a[i][j - 1] = min(-moveTime[i][j - 1], t) - 1;
        q.emplace(a[i][j - 1], i, j - 1);
      }

      if (j != size(moveTime.front()) - 1 &&
          min(-moveTime[i][j + 1], t) - 1 > a[i][j + 1]) {
        a[i][j + 1] = min(-moveTime[i][j + 1], t) - 1;
        q.emplace(a[i][j + 1], i, j + 1);
      }
    }
  }
};
