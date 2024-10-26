class Solution {
public:
  int possibleStringCount(string word) {
    int n = 1;

    for (char c = ' '; auto &&x : word)
      n += static_cast<int>(exchange(c, x) == x);

    return n;
  }
};

