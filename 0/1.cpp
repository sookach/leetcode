class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> u;

    for (int i = 0; i != size(nums); ++i) {
      if (u.contains(nums[i] - target))
        return {i, u[nums[i] - target]};
      u[nums[i]] = i;
    }

    return {};
  }
};

