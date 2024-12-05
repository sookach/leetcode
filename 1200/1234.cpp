class Solution {
public:
  int balancedString(string s) {
    auto f = [](auto &&x) {
      switch (x) {
      default:
        return 0;
      case 'W':
        return 1;
      case 'E':
        return 2;
      case 'R':
        return 3;
      }
    };
    array<int, 4> a = {};

    for (auto &&x : s)
      ++a[f(x)];

    int i = -1, j = size(s);

    for (; i != j - 1;)
      ([&](auto &&n) {
        auto a1 = a;
        auto g = [&] {
          for (auto n1 = n; auto &&x : a1)
            if (x > size(s) / 4 || (n1 -= size(s) / 4 - x) < 0)
              return false;

          return true;
        };

        for (int i = 0; i != n; ++i)
          --a1[f(s[i])];

        if (g())
          return true;

        for (auto i = n; i != size(s); ++i) {
          --a1[f(s[i])];
          ++a1[f(s[i - n])];
          if (g())
            return true;
        }

        return false;
      }(i + (j - i) / 2)
           ? j
           : i) = i + (j - i) / 2;

    return j;
  }
};
