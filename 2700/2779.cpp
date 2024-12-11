class Solution {
public:
  int maximumBeauty(vector<int> &nums, int k) {
    int n = 0;

    ranges::sort(nums);

    for (int i = 0, j = 0; j != size(nums); ++j) {
      for (; nums[j] - nums[i] > 2 * k; ++i)
        ;
      n = max(n, j - i + 1);
    }

    return n;
  }
};
