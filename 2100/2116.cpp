class Solution {
public:
  bool canBeValid(string s, string locked) {
    if (size(s) % 2 != 0)
      return false;

    auto f = [&](int i, int j, char c, auto f) {
      int n1 = 0, n2 = 0;

      for (; i != j; i = f(i, 1)) {
        if (locked[i] == '1') {
          if (s[i] == c)
            ++n1;
          else if (n1 != 0)
            --n1;
          else if (n2 != 0)
            --n2;
          else
            return false;
        } else {
          ++n2;
        }
      }

      return n1 <= n2;
    };

    return f(0, size(s), '(', plus()) && f(size(s) - 1, -1, ')', minus());
  }
};
