class Solution {
public:
  int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
    return (size(nums2) % 2 == 0 ? 0 : ranges::fold_left(nums1, 0, bit_xor())) ^
           (size(nums1) % 2 == 0 ? 0 : ranges::fold_left(nums2, 0, bit_xor()));
  }
};
