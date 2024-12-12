class Solution {
public:
  bool checkIfCanBreak(string s1, string s2) {
    auto f = [](auto &&x, auto &&y) {
      for (int i = 0; i != size(x); ++i)
        if (y[i] > x[i])
          return false;
      return true;
    };

    ranges::sort(s1);
    ranges::sort(s2);

    return f(s1, s2) || f(s2, s1);
  }
};
