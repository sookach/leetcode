class Solution {
public:
  int longestSquareStreak(vector<int> &nums) {
    unordered_map<uint64_t, int> u;
    int n = 0;

    for (auto &&x : nums)
      u[x] = 1;

    ranges::sort(nums);
    nums.erase(begin(ranges::unique(nums)), end(nums));

    for (uint64_t x : nums)
      if (u.contains(x * x))
        u[x * x] += u[x];

    for (auto &&[x, y] : u)
      n = max(n, y);

    return n == 1 ? -1 : n;
  }
};
