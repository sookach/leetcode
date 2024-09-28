class Solution {
  unordered_map<int, int> u = {{0, 1}};

public:
  int combinationSum4(vector<int> &nums, int target) {
    return u.contains(target)
               ? u[target]
               : u[target] =
                     ranges::fold_left(nums, 0, [&](auto &&x, auto &&y) {
                       return x + (y <= target
                                       ? combinationSum4(nums, target - y)
                                       : 0);
                     });
  }
};
