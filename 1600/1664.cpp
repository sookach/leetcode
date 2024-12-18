class Solution {
public:
  int waysToMakeFair(vector<int> &nums) {
    int n = 0;
    pair<int, int> p1, p2;

    for (int i = 0; i != size(nums); ++i)
      (i % 2 == 0 ? p1 : p2).first += nums[i];

    for (int i = 0; i != size(nums); ++i) {
      (i % 2 == 0 ? p1 : p2).first -= nums[i];
      n += static_cast<int>(p1.first + p2.second == p1.second + p2.first);
      (i % 2 == 0 ? p1 : p2).second += nums[i];
    }

    return n;
  }
};
