class Solution {
public:
  int maximumSum(vector<int> &arr) {
    array<array<int, 2>, 100'000> dp;
    auto n = arr.front();

    dp.front() = {arr.front(), arr.front()};

    for (int i = 1; i != size(arr); ++i) {
      dp[i].front() = max(dp[i - 1].front() + arr[i], arr[i]);
      dp[i].back() =
          max({dp[i - 1].back() + arr[i], dp[i - 1].front(), arr[i]});
      n = max(n, dp[i].back());
    }

    return n;
  }
};
