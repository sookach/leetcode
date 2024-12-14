class Solution {
public:
  long long continuousSubarrays(vector<int> &nums) {
    long long n = 0;
    multiset<int> m;

    for (int i = 0, j = 0; j != size(nums); ++j) {
      m.insert(nums[j]);

      for (; abs(*cbegin(m) - nums[j]) > 2 || abs(*crbegin(m) - nums[j]) > 2;
           ++i)
        m.erase(m.find(nums[i]));

      n += size(m);
    }

    return n;
  }
};
