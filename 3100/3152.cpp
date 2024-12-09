class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    vector<int> v1;
    vector<bool> v2;

    for (int i = 0; i != size(nums);) {
      v1.push_back(i);
      for (++i; i != size(nums) && nums[i] % 2 + nums[i - 1] % 2 == 1; ++i)
        ;
    }

    for (auto &&x : queries)
      v2.push_back(ranges::upper_bound(v1, x.front()) ==
                   ranges::upper_bound(v1, x.back()));

    return v2;
  }
};
