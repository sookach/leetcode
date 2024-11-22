class Solution {
public:
  int brokenCalc(int startValue, int target) {
    int n = 0;

    for (; startValue < target; ++n)
      target = target % 2 == 0 ? target / 2 : target + 1;

    return n + startValue - target;
  }
};
