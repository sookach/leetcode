class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    array<int, 100'001> a = {};
    long long x = 0, y = 0, n = 0;

    for (int i = 0; i != k; ++i) {
      x += static_cast<int>(++a[nums[i]] == 1);
      y += nums[i];
    }

    if (x == k)
      n = y;

    for (int i = k; i != size(nums); ++i) {
      x += static_cast<int>(++a[nums[i]] == 1) -
           static_cast<int>(--a[nums[i - k]] == 0);
      y += nums[i] - nums[i - k];
      if (x == k)
        n = max(n, y);
    }

    return n;
  }
};
