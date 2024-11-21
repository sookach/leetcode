class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    array<int, 30'000> a1 = {}, a2 = {}, a3 = {};
    auto x = ranges::max(nums);

    a1.front() = a3.front() = nums.front();
    for (int i = 1, x = nums.front(), y = nums.front(); i != size(nums); ++i) {
      x += nums[i];
      a1[i] = max(a1[i - 1], x);
      a3[i] = y = max(nums[i], y + nums[i]);
    }

    a2[size(nums) - 1] = nums.back();
    for (int i = size(nums) - 2, x = nums.back(); i != -1; --i) {
      x += nums[i];
      a2[i] = max(a2[i + 1], x);
    }

    for (int i = 0; i != size(nums) - 1; ++i)
      x = max({x, a1[i] + a2[i + 1], a3[i]});

    return max(x, a3[size(nums) - 1]);
  }
};
