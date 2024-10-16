class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    string s = "";

    for (;;) {
      char x = ' ';
      auto a1 = size(s) < 2 || s.substr(size(s) - 2) != "aa" ? a : 0,
           b1 = size(s) < 2 || s.substr(size(s) - 2) != "bb" ? b : 0,
           c1 = size(s) < 2 || s.substr(size(s) - 2) != "cc" ? c : 0;

      if (a1 != 0 && max({a1, b1, c1}) == a) {
        x = 'a';
        --a;
      } else if (b1 != 0 && max({a1, b1, c1}) == b) {
        x = 'b';
        --b;
      } else if (c1 != 0 && max({a1, b1, c1}) == c) {
        x = 'c';
        --c;
      }

      if (x == ' ')
        break;

      s.push_back(x);
    }

    return s;
  }
};
