class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    set u(cbegin(nums), cend(nums));
    array<int, 20'001> dp = {};

    for (auto &&x : nums)
      dp[x] += x;

    for (auto &&x : u)
      if (x > 2)
        dp[x] += *max_element(cbegin(dp) + 1, cbegin(dp) + x - 1);

    return ranges::max(dp);
  }
};
