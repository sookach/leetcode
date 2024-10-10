class Solution {
public:
  int maxWidthRamp(vector<int> &nums) {
    array<int, 50'000> a = {};
    auto f = [&](auto &&n) {
      for (auto i = n; i != size(nums); ++i)
        if (nums[i] >= a[i - n])
          return true;
      return false;
    };

    a.front() = nums.front();
    for (int i = 1; i != size(nums); ++i)
      a[i] = min(a[i - 1], nums[i]);

    int i = 0, j = size(nums) + 1;
    for (; i != j - 1;)
      (f(i + (j - i) / 2) ? i : j) = i + (j - i) / 2;

    return i;
  }
};
