class Solution {
public:
  bool isPossibleDivide(vector<int> &nums, int k) {
    if (size(nums) % k != 0)
      return false;

    multiset m(cbegin(nums), cend(nums));

    for (; !empty(m);) {
      auto n = *cbegin(m);
      m.erase(cbegin(m));

      for (int i = 1; i != k; ++i) {
        auto j = m.find(n + 1);
        if (j == cend(m))
          return false;
        n = *j;
        m.erase(j);
      }
    }

    return true;
  }
};
