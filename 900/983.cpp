class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    array<int, 400> dp = {};

    ranges::fill(dp, numeric_limits<int>::max());

    dp[days.front()] = 0;

    for (int i = 0; i != size(days); ++i) {
      if (i != 0)
        dp[days[i]] = dp[days[i - 1] + 1];

      dp[days[i] + 1] = min(dp[days[i] + 1], dp[days[i]] + costs.front());

      for (int j = 1; j <= 7; ++j)
        dp[days[i] + j] = min(dp[days[i] + j], dp[days[i]] + costs[1]);

      for (int j = 1; j <= 30; ++j)
        dp[days[i] + j] = min(dp[days[i] + j], dp[days[i]] + costs.back());
    }

    return dp[days.back() + 1];
  }
};
