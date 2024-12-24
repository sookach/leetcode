class Solution {
public:
  int tupleSameProduct(vector<int> &nums) {
    unordered_map<int, int> u;
    int n = 0;

    for (int i = 0; i != size(nums) - 1; ++i)
      for (int j = i + 1; j != size(nums); ++j)
        ++u[nums[i] * nums[j]];

    for (auto &&[x, y] : u)
      if (y != 1)
        n += (y * (y - 1)) / 2;

    return n * 8;
  }
};
