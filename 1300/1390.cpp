class Solution {
public:
  int sumFourDivisors(vector<int> &nums) {
    int n = 0;

    for (auto &&x : nums) {
      vector v = {1, x};
      for (int i = 2; i <= sqrt(x); ++i)
        if (x % i == 0) {
          v.push_back(i);
          if (x / i != i)
            v.push_back(x / i);
        }
      if (size(v) == 4)
        n += ranges::fold_left(v, 0, plus());
    }

    return n;
  }
};
