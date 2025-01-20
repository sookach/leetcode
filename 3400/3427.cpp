class Solution {
public:
  int subarraySum(vector<int> &nums) {
    int n = 0;

    for (int i = 0; i != size(nums); ++i)
      for (int j = max(i - nums[i], 0); j <= i; ++j)
        n += nums[j];

    return n;
  }
};
