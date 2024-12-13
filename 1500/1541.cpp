class Solution {
public:
  int minInsertions(string s) {
    int n = 0;
    int x = 0;

    for (int i = 0; i != size(s);) {
      if (s[i] == '(') {
        ++x;
        ++i;
      } else {
        if (x == 0)
          ++n;
        x = max(x - 1, 0);

        if (i == size(s) - 1 || s[i + 1] != ')') {
          --i;
          ++n;
        }
        i += 2;
      }
    }

    return n + x * 2;
  }
};
