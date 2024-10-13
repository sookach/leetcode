class Solution {
public:
  bool isPossible(vector<int> &nums) {
    unordered_map<int, int> u1, u2;

    for (auto &&x : nums)
      ++u1[x];

    for (int x : nums) {
      if (u1[x] == 0)
        continue;

      if (u2[x - 1] != 0) {
        --u1[x];
        ++u2[x];
        --u2[x - 1];
        continue;
      }

      if (u1[x + 1] == 0 || u1[x + 2] == 0)
        return false;

      --u1[x];
      --u1[x + 1];
      --u1[x + 2];
      ++u2[x + 2];
    }

    return true;
  }
};
