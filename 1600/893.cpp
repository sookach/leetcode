class Solution {
public:
  int numSpecialEquivGroups(vector<string> &words) {
    unordered_set<string> u;

    for (auto &&x : words) {
      string s1, s2;
      for (int i = 0; i != size(x); ++i)
        (i % 2 == 0 ? s1 : s2).push_back(x[i]);
      ranges::sort(s1);
      ranges::sort(s2);
      u.insert(s1 + " " + s2);
    }

    return size(u);
  }
};
