class Solution {
public:
  int minimumMountainRemovals(vector<int> &nums) {
    auto h = [](auto &&x) {
      return hash<int>()(x.first) ^ hash<int>()(x.second);
    };
    unordered_map<pair<int, int>, int, decltype(h)> u;
    int n = 0;

    for (auto x : nums) {
      int n1 = 1, n2 = 1;

      for (auto [a, b] : u)
        if (a.first > x && b != 1)
          n2 = max(n2, b + 1);
        else if (a.first < x && a.second == 0)
          n1 = max(n1, b + 1);

      u[{x, 0}] = n1;
      if (n2 != 1)
        u[{x, 1}] = n2;
    }

    for (auto &&[x, y] : u)
      if (x.second == 1)
        n = max(n, y);

    return size(nums) - n;
  }
};
