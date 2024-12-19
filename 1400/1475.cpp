class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    for (auto i = begin(prices); i != end(prices) - 1; ++i) {
      auto j = find_if(i + 1, end(prices), [&](auto &&x) { return x <= *i; });
      *i -= j == end(prices) ? 0 : *j;
    }

    return prices;x
  }
};
