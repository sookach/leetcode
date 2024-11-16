class Solution {
public:
  int expressiveWords(string s, vector<string> &words) {
    vector<vector<pair<int, int>>> v1;
    vector<pair<int, int>> v2;

    for (auto &&x : s)
      if (empty(v2) || v2.back().first != x)
        v2.emplace_back(x, 1);
      else
        ++v2.back().second;

    for (auto &&x : words)
      for (v1.emplace_back(); auto &&y : x)
        if (empty(v1.back()) || v1.back().back().first != y)
          v1.back().emplace_back(y, 1);
        else
          ++v1.back().back().second;

    return ranges::count_if(v1, [&](auto &&x) {
      if (size(x) != size(v2))
        return false;

      for (int i = 0; i != size(x); ++i)
        if (x[i].first != v2[i].first || x[i].second > v2[i].second ||
            v2[i].second > x[i].second && v2[i].second < 3)
          return false;

      return true;
    });
  }
};
