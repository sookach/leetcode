class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    auto n = numeric_limits<int>::min();

    for (int y = 0; auto &&x : values) {
      n = max(n, x + y);
      y = max(y, x);
      --y;
    }

    return n;
  }
};
