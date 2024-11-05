class Solution {
public:
  int minChanges(string s) {
    int n = 0;

    for (int i = 0; i != size(s); i += 2)
      n += abs(s[i] - s[i + 1]);

    return n;
  }
};
