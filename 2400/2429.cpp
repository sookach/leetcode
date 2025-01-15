class Solution {
public:
  int minimizeXor(int num1, int num2) {
    for (; popcount<unsigned>(num1) < popcount<unsigned>(num2);)
      num1 |= num1 + 1;

    for (; popcount<unsigned>(num1) > popcount<unsigned>(num2);)
      num1 &= num1 - 1;

    return num1;
  }
};
