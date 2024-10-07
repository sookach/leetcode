class Solution {
public:
  int minLength(string s) {
    for (;;) {
      auto n = size(s);
      auto i = ranges::search(s, "AB"sv);
      s.erase(cbegin(i), cend(i));
      i = ranges::search(s, "CD"sv);
      s.erase(cbegin(i), cend(i));
      if (size(s) == n)
        return n;
    }
  }
};

