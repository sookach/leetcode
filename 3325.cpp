class Solution {
public:
  int numberOfSubstrings(string s, int k) {
    array<array<int, 26>, 3'001> a = {};
    int n = 0;

    for (int i = 0; i != size(s); ++i) {
      ++a[i][s[i] - 'a'];
      n += static_cast<int>(
          ranges::contains(a[i], true, [&](auto &&x) { return x >= k; }));
      for (int j = i - 1; j != -1; --j) {
        for (int c = 0; c != 26; ++c) {
          if (a[i][c] - a[j][c] >= k) {
            ++n;
            break;
          }
        }
      }
      a[i + 1] = a[i];
    }

    return n;
  }
};
