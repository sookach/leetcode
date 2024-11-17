class Solution {
public:
  int numFactoredBinaryTrees(vector<int> &arr) {
    unordered_map<int, uint64_t> dp;
    int n = 0;

    ranges::sort(arr);

    for (auto &&x : arr) {
      dp[x] = 1;
      for (auto &&y : arr) {
        if (y > x)
          break;
        if (x % y == 0 && dp.contains(x / y))
          dp[x] = (dp[x] + dp[y] * dp[x / y]) % 1'000'000'007;
      }
    }

    return ranges::fold_left(arr, 0, [&](auto &&x, auto &&y) {
      return (x + dp[y]) % 1'000'000'007;
    });
  }
};
