class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    ranges::sort(costs, {}, [](auto &&x) { return x.front() - x.back(); });
    return accumulate(cbegin(costs), cbegin(costs) + size(costs) / 2, 0,
                      [](auto &&x, auto &&y) { return x + y.front(); }) +
           accumulate(cbegin(costs) + size(costs) / 2, cend(costs), 0,
                      [](auto &&x, auto &&y) { return x + y.back(); });
  }
};
