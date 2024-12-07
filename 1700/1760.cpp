class Solution {
public:
  int minimumSize(vector<int> &nums, int maxOperations) {
    int i = 0, j = ranges::max(nums);

    for (; i != j - 1;) {
      ([&](auto &&k) {
        return ranges::fold_left(nums, 0, [&](auto &&x, auto &&y) {
                 return x + static_cast<int>(y > k) *
                                (ceil(static_cast<double>(y) / k) - 1);
               }) <= maxOperations;
      }(i + (j - i) / 2)
           ? j
           : i) = i + (j - i) / 2;
    }

    return j;
  }
};
