class Solution {
public:
  int countMaxOrSubsets(vector<int> &nums) {
    int n = 0;
    auto x = ranges::fold_left(nums, 0, bit_or());

    for (unsigned i = 0; i != 1 << size(nums); ++i) {
      bitset<16> b(i);
      int y = 0;
      for (int j = 0; j != size(nums); ++j)
        if (b.test(j))
          y |= nums[j];
      n += static_cast<int>(x == y);
    }

    return n;
  }
};
