class Solution {
public:
  int maxAdjacentDistance(vector<int> &nums) {
    int n = 0;

    for (int i = 0; i != size(nums); ++i)
      n = max(n, abs(nums[i] - nums[(i + 1) % size(nums)]));

    return n;
  }
};
