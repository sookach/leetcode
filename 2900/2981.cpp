class Solution {
public:
  int maximumLength(string s) {
    array<array<int, 26>, 51> a = {};

    for (int i = 0, j = 0; j != size(s); ++j) {
      if (s[i] != s[j])
        i = j;
      for (int n = 1; n <= j - i + 1; ++n)
        ++a[n][s[j] - 'a'];
    }

    for (int i = 50; i != 0; --i)
      if (ranges::contains(a[i], true, [](auto &&x) { return x >= 3; }))
        return i;

    return -1;
  }
};
