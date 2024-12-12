class Solution {
public:
  int numSub(string s) {
    int n = 0;

    for (int i = 0, j = 0; j != size(s); ++j) {
      if (s[j] == '0')
        i = j + 1;
      else
        n = (n + j - i + 1) % 1'000'000'007;
    }

    return n;
  }
};
