class Solution {
public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    bitset<10'001> b;
    int i = 0, j = 0, x = 0;
    auto f = [&] {
      for (++j; j <= n && b.test(j); ++j)
        ;
    };

    for (auto &&x : banned)
      b.set(x);

    for (f(); (x += j) <= maxSum && j <= n; f())
      ++i;

    return i;
  }
};
