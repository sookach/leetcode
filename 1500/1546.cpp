class Solution {
public:
  int maxNonOverlapping(vector<int> &nums, int target) {
    int n = 0;
    unordered_map<int, int> u = {{0, -1}};

    for (int i = 0, x = 0, y = -1; i != size(nums); ++i) {
      x += nums[i];

      if (u.contains(x - target) && u[x - target] >= y) {
        ++n;
        y = i;
      }

      u[x] = i;
    }

    return n;
  }
};
