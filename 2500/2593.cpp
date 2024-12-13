class Solution {
public:
  long long findScore(vector<int> &nums) {
    bitset<100'002> b;
    vector<pair<int, int>> v;
    long long n = 0;

    for (int i = 0; i != size(nums); ++i)
      v.emplace_back(nums[i], i + 1);

    ranges::sort(v);

    for (auto &&[x, y] : v) {
      if (b.test(y))
        continue;

      n += x;
      b.set(y - 1);
      b.set(y + 1);
    }

    return n;
  }
};
