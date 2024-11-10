class Solution {
public:
  int minimumSubarrayLength(vector<int> &nums, int k) {
    array<int, 32> a = {};
    auto f1 = [&](auto &&f, unsigned x) {
      bitset<32> b(x);
      for (int i = 0; i != 32; ++i)
        if (b.test(i))
          a[i] = f(a[i], 1);
    };
    auto f2 = [&] {
      bitset<32> b;
      for (int i = 0; i != 32; ++i)
        if (a[i] != 0)
          b.set(i);
      return b.to_ulong();
    };
    auto n = numeric_limits<int>::max();

    for (int i = 0, j = 0; j != size(nums); ++j) {
      for (f1(plus(), nums[j]); i <= j && f2() >= k; ++i) {
        n = min(n, j - i + 1);
        f1(minus(), nums[i]);
      }
    }

    return n == numeric_limits<int>::max() ? -1 : n;
  }
};
