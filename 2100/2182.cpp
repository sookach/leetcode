class Solution {
public:
  string repeatLimitedString(string s, int repeatLimit) {
    array<int, 26> a = {};
    int i = 0;

    for (auto &&x : s)
      ++a[x - 'a'];

    for (int n = 1; i != size(s); ++i) {
      int j = 25;
      for (; j != -1; --j)
        if (a[j] != 0 && (i == 0 || s[i - 1] != j + 'a' || n != repeatLimit))
          break;
      if (j == -1)
        break;
      --a[j];
      n = i == 0 || s[i - 1] != j + 'a' ? 1 : n + 1;
      s[i] = j + 'a';
    }

    s.resize(i);
    return s;
  }
};
