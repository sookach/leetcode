class Solution {
public:
  int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
    return ranges::fold_left(nums1, 0,
                             [&](auto &&x, auto &&y) {
                               return size(nums2) % 2 == 0 ? x : x ^ y;
                             }) ^
           ranges::fold_left(nums2, 0, [&](auto &&x, auto &&y) {
             return size(nums1) % 2 == 0 ? x : x ^ y;
           });
  }
};
