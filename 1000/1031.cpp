class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    auto f = [&](auto &&i, auto &&j) {
      if (j - i < secondLen)
        return numeric_limits<int>::min();

      int x = 0, y = 0;
      for (int k = i; k != i + secondLen; ++k)
        x += nums[k];

      y = x;
      for (int k = i + secondLen; k != j; ++k)
        x = max(x, y += nums[k] - nums[k - secondLen]);

      return x;
    };
    int x = 0, y = 0;
    for (int i = 0; i != firstLen; ++i)
      y += nums[i];

    x = y + f(firstLen, size(nums));
    for (int i = firstLen; i != size(nums); ++i) {
      y += nums[i] - nums[i - firstLen];
      x = max(x, y + max(f(0, i - firstLen), f(i + 1, size(nums))));
    }

    return x;
  }
};
