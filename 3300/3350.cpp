class Solution {
public:
  bool hasIncreasingSubarrays(vector<int> &nums, int k) {
    bitset<100> b;
    deque<int> q;

    for (int i = 0; i != size(nums); ++i) {
      if (!empty(q) && q.front() <= i - k)
        q.pop_front();

      for (; !empty(q) && nums[q.back()] >= nums[i]; q.pop_back())
        ;

      q.push_back(i);

      if (size(q) == k)
        b.set(i);
    }

    for (int i = k - 1; i != size(nums) - k; ++i)
      if (b.test(i) && b.test(i + k))
        return true;

    return false;
  }
};
