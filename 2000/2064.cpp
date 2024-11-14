class Solution {
public:
  int minimizedMaximum(int n, vector<int> &quantities) {
    auto f = [&](auto &&x) {
      int j = 0;

      for (int i = 0, y = 0; i != n && j != size(quantities); ++i) {
        if (y == 0)
          y = quantities[j];
        y -= min(x, y);
        j += static_cast<int>(y == 0);
      }

      return j == size(quantities);
    };
    int i = 0, j = 100'000;

    for (; i != j - 1;)
      (f(i + (j - i) / 2) ? j : i) = i + (j - i) / 2;

    return j;
  }
};
