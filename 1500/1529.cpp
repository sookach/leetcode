class Solution {
public:
  int minFlips(string target) {
    int n = 0;

    for (int y = '0'; auto &&x : target) {
      n += static_cast<int>(x != y);
      y = x;
    }

    return n;
  }
};
