class Solution {
public:
  bool isBalanced(string num) {
    int x = 0, y = 0;

    for (int i = 0; i != size(num); ++i)
      (i % 2 == 0 ? x : y) += num[i] - '0';

    return x == y;
  }
};
