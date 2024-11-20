class Solution {
public:
  int takeCharacters(string s, int k) {
    auto n = numeric_limits<int>::max();
    auto a = ranges::fold_left(s, array<int, 3>(), [](auto &&x, auto &&y) {
      ++x[y - 'a'];
      return x;
    });

    if (!ranges::all_of(a, [&](auto &&x) { return x >= k; }))
      return -1;

    for (int i = 0, j = 0; j < size(s); ++j) {
      for (--a[s[j] - 'a']; a[s[j] - 'a'] < k; ++a[s[i++] - 'a'])
        ;
      n = min<int>(n, size(s) - j + i - 1);
    }

    return n;
  }
};
