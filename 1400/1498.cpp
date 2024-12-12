class Solution {
public:
  int numSubseq(vector<int> &nums, int target) {
    array<int, 100'000> a = {};
    int n = 0;

    fill(begin(a), begin(a) + size(nums), 1);

    for (int i = 1; i != size(nums); ++i)
      a[i] = (a[i - 1] * 2) % 1'000'000'007;

    ranges::sort(nums);

    for (int i = 0, j = size(nums) - 1; i <= j;) {
      if (nums[i] + nums[j] <= target) {
        n = (n + a[j - i]) % 1'000'000'007;
        ++i;
      } else {
        --j;
      }
    }

    return n;
  }
};
