class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    vector<pair<int, int>> v1;
    vector<int> v2;

    ranges::sort(items);

    for (auto &&x : items) {
      if (empty(v1)) {
        v1.emplace_back(x.front(), x.back());
      } else if (v1.back().second < x.back()) {
        if (v1.back().first == x.front())
          v1.back().second = x.back();
        else
          v1.emplace_back(x.front(), x.back());
      }
    }

    for (auto &&x : queries) {
      auto i = ranges::lower_bound(v1, x, {}, &::pair<int, int>::first);

      if (i == cend(v1)) {
        v2.push_back(v1.back().second);
        continue;
      }

      i -= static_cast<int>(i->first != x);
      v2.push_back(i == cbegin(v1) - 1 ? 0 : i->second);
    }

    return v2;
  }
};
