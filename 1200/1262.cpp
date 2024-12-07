class Solution {
public:
  int maxSumDivThree(vector<int> &nums) {
    array<int, 3> dp = {};

    for (auto &&x : nums)
      for (auto &&y : array(dp))
        dp[(x + y) % 3] = max(dp[(x + y) % 3], y + x);

    return dp.front();
  }
};
