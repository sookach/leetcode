class Solution {
public:
  bool checkPossibility(vector<int> &nums) {
    if (size(nums) < 3)
      return true;

    int i = 0;

    for (; i != size(nums) - 1 && nums[i] <= nums[i + 1]; ++i)
      ;

    if (i == size(nums))
      return true;

    auto v1 = nums, v2 = nums;

    v1.erase(begin(v1) + i);
    v2.erase(begin(v2) + i + 1);

    for (i = 0; i != size(v1) - 1 && v1[i] <= v1[i + 1]; ++i)
      ;

    if (i == size(v1) - 1)
      return true;

    for (i = 0; i != size(v2) - 1; ++i)
      if (v2[i] > v2[i + 1])
        return false;

    return true;
  }
};
