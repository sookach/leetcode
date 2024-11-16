class Solution {
public:
  vector<int> resultsArray(vector<int> &nums, int k) {
    vector<int> v;
    deque<int> q;

    for (int i = 0; i != k - 1; ++i) {
      for (; !empty(q) && nums[q.back()] != nums[i] - 1; q.pop_back())
        ;
      q.push_back(i);
    }

    for (int i = k - 1; i != size(nums); ++i) {
      if (!empty(q) && q.front() <= i - k)
        q.pop_front();

      for (; !empty(q) && nums[q.back()] != nums[i] - 1; q.pop_back())
        ;

      q.push_back(i);
      v.push_back(size(q) == k ? nums[q.back()] : -1);
    }

    return v;
  }
};
