class Solution {
public:
  bool rotateString(string s, string goal) {
    for (int i = 0; i != size(s); ++i) {
      if (s == goal)
        return true;
      ranges::rotate(s, begin(s) + 1);
    }

    return false;
  }
};
