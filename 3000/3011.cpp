class Solution {
public:
  bool canSortArray(vector<int> &nums) {
    for (int n = 0; n != size(nums); ++n)
      for (int i = 0; i != size(nums) - 1; ++i)
        if (popcount(static_cast<unsigned>(nums[i])) ==
                popcount(static_cast<unsigned>(nums[i + 1])) &&
            nums[i] > nums[i + 1])
          swap(nums[i], nums[i + 1]);

    return ranges::is_sorted(nums);
  }
};
