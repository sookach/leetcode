class Solution {
public:
  int partitionDisjoint(vector<int> &nums) {
    array<int, 100'000> a1 = {}, a2 = {};

    a1.front() = nums.front();
    for (int i = 1; i != size(nums); ++i)
      a1[i] = max(a1[i - 1], nums[i]);

    a2[size(nums) - 1] = nums.back();
    for (int i = size(nums) - 2; i != -1; --i)
      a2[i] = min(a2[i + 1], nums[i]);

    for (int i = 0; i != size(nums) - 1; ++i)
      if (a1[i] <= a2[i + 1])
        return i + 1;

    return 0;
  }
};
