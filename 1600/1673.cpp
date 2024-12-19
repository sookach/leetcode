class Solution {
public:
  vector<int> mostCompetitive(vector<int> &nums, int k) {
    if (ranges::is_sorted(nums)) {
      nums.resize(k);
      return nums;
    }

    if (ranges::is_sorted(nums, greater())) {
      nums.erase(cbegin(nums), cend(nums) - k);
      return nums;
    }

    vector<int> v;

    for (auto i = cbegin(nums); k != 0; --k) {
      i = min_element(i, cend(nums) - k + 1);
      v.push_back(*i);
      ++i;
    }

    return v;
  }
};
