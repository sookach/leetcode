class Solution {
public:
  int findBestValue(vector<int> &arr, int target) {
    auto f = [&](auto &&n) {
      return ranges::fold_left(
                 arr, 0, [&](auto &&x, auto &&y) { return x + min(y, n); }) -
             target;
    };
    int i = 0, j = ranges::max(arr);

    for (; i != j - 1;)
      (f(i + (j - i) / 2) < 0 ? i : j) = i + (j - i) / 2;

    return -f(i) <= f(j) ? i : j;
  }
};
