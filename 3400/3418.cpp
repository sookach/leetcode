class Solution {
public:
  int maximumAmount(vector<vector<int>> &coins) {
    array<array<array<int, 3>, 501>, 501> a = {};

    for (auto &&x : a)
      for (auto &&y : x)
        ranges::fill(y, numeric_limits<int>::min());

    ranges::fill(a.front().front(), 0);

    for (int i = 0; i != size(coins); ++i) {
      for (int j = 0; j != size(coins.front()); ++j) {
        for (int k = 0; k != 3; ++k) {
          a[i + 1][j][k] = max(a[i + 1][j][k], a[i][j][k] + coins[i][j]);
          a[i][j + 1][k] = max(a[i][j + 1][k], a[i][j][k] + coins[i][j]);
        }

        if (coins[i][j] < 0) {
          a[i + 1][j][1] = max(a[i + 1][j][1], a[i][j].front());
          a[i][j + 1][1] = max(a[i][j + 1][1], a[i][j].front());
          a[i + 1][j].back() = max(a[i + 1][j].back(), a[i][j][1]);
          a[i][j + 1].back() = max(a[i][j + 1].back(), a[i][j][1]);
        }
      }
    }

    return ranges::max(a[size(coins)][size(coins.front()) - 1]);
  }
};
