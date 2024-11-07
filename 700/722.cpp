class Solution {
public:
  vector<string> removeComments(vector<string> &source) {
    vector<string> v(1);
    string s = ranges::fold_left(
        source, string(), [](auto &&x, auto &&y) { return x + y + "\n"; });
    s.pop_back();

    for (int i = 0; i != size(s); ++i) {
      if (s.substr(i, 2) == "/*") {
        auto j = s.find("*/", i + 2);
        if (j == string::npos)
          break;
        i = j + 1;
        continue;
      }

      if (s.substr(i, 2) == "//") {
        auto j = s.find('\n', i);
        if (j == string::npos)
          break;
        i = j - 1;
        continue;
      }

      if (s[i] == '\n') {
        if (!empty(v.back()))
          v.emplace_back();
      } else {
        v.back().push_back(s[i]);
      }
    }

    return v;
  }
};
