class Solution {
public:
  int maxScore(string s) {
    int n1 = 0, n2 = ranges::count(s, '1'), n3 = 0;

    for (int i = 0; i != size(s) - 1; ++i) {
      s[i] == '0' ? ++n3 : --n2;
      n1 = max(n1, n2 + n3);
    }

    return n1;
  }
};
