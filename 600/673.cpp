class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    array<pair<int, int>, 2'000> a = {};
    int n1 = 1, n2 = 0;

    for (int i = 0; i != size(nums); ++i) {
      a[i] = {1, 1};

      for (int j = i - 1; j != -1; --j) {
        if (nums[j] >= nums[i])
          continue;

        if (a[j].first + 1 > a[i].first)
          a[i] = {a[j].first + 1, 0};

        if (a[j].first + 1 == a[i].first)
          a[i].second += a[j].second;
      }

      if (a[i].first > n1) {
        n1 = a[i].first;
        n2 = 0;
      }

      if (a[i].first == n1)
        n2 += a[i].second;
    }

    return n2;
  }
};
