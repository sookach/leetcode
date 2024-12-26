class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    unordered_map<int, int> u1 = {{0, 1}}, u2;
    int n = 0;

    for (auto &&x : nums) {
      for (auto &&[y, z] : u1) {
        u2[y + x] += z;
        u2[y - x] += z;
      }
      u1 = std::move(u2);
      u2.clear();
    }

    for (auto &&[x, y] : u1)
      n += y * static_cast<int>(x == target);

    return n;
  }
};
