class Solution {
public:
  int minimumLength(string s) {
    array<int, 26> a = {};

    for (auto &&x : s)
      ++a[x - 'a'];

    return ranges::fold_left(a, 0, [](auto &&x, auto &&y) {
      return x + (y == 0 ? 0 : y % 2 == 0 ? 2 : 1);
    });
  }
};
