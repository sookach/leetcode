class Solution {
public:
  vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
    vector<int> v;
    multiset s(cbegin(nums1), cend(nums1));

    for (auto &&x : nums2) {
      auto i = s.upper_bound(x);
      if (i != cend(s)) {
        v.push_back(*i);
        s.erase(i);
      } else {
        v.push_back(*cbegin(s));
        s.erase(cbegin(s));
      }
    }

    return v;
  }
};
