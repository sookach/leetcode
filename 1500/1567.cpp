class Solution {
public:
  int getMaxLen(vector<int> &nums) {
    int n = 0;

    for (auto i = cbegin(nums);;) {
      i = find_if(i, cend(nums), [](auto &&x) { return x != 0; });
      if (i == cend(nums))
        break;
      auto j = find(i, cend(nums), 0);
      [&](auto &&i, auto &&j) {
        int x = 0;
        for (auto i1 = i, k = i - 1; i1 != j; ++i1) {
          x += static_cast<int>(*i1 < 0);
          if (x % 2 == 0)
            n = max<int>(n, i1 - i + 1);
          else if (k != i - 1)
            n = max<int>(n, i1 - k);
          if (*i1 < 0 && k == i - 1)
            k = i1;
        }
      }(i, j);
      i = j;
    }

    return n;
  }
};
