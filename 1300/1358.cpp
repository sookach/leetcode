class Solution {
public:
  int numberOfSubstrings(string s) {
    array a = {-1, -1, -1};
    int n = 0;

    for (int i = 0; i != size(s); ++i) {
      a[s[i] - 'a'] = i;
      n += ranges::min(a) + 1;
    }

    return n;
  }
};
