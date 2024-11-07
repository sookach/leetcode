class Solution {
public:
  int largestCombination(vector<int> &candidates) {
    array<int, 32> a = {};

    for (auto &&x : candidates) {
      bitset<32> b(static_cast<unsigned>(x));
      for (int i = 0; i != 32; ++i)
        a[i] += static_cast<int>(b.test(i));
    }

    return ranges::max(a);
  }
};
