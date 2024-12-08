class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &events) {
    map<int, int> m;
    auto n = ranges::max(events, {}, [](auto &&x) { return x.back(); }).back();

    ranges::sort(events, greater(), [](auto &&x) { return x.front(); });

    for (int n = 0; auto &&x : events)
      if (x.back() > n)
        m[x.front()] = n = x.back();

    for (auto &&x : events)
      if (auto i = m.upper_bound(x[1]); i != cend(m))
        n = max(n, x.back() + i->second);

    return n;
  }
};
