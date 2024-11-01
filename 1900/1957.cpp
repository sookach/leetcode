class Solution {
public:
  string makeFancyString(string s) {
    string t;

    for (auto &&x : s)
      if (size(t) <= 1 || t[size(t) - 2] != x || t.back() != x)
        t.push_back(x);

    return t;
  }
};
