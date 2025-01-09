class Solution {
public:
  int prefixCount(vector<string> &words, string pref) {
    return ranges::fold_left(words, 0, [&](auto &&x, auto &&y) {
      return x + static_cast<int>(y.substr(0, size(pref)) == pref);
    });
  }
};
