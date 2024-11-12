class Solution {
public:
  int maxIncreasingSubarrays(vector<int> &nums) {
    bitset<200'000> b;
    deque<int> q;
    int i = 1, j = size(nums);

    for (; i != j - 1;) {
      auto k = i + (j - i) / 2;
      ([&] {
        b.reset();
        q.clear();

        for (int i = 0; i != size(nums); ++i) {
          if (!empty(q) && q.front() <= i - k)
            q.pop_front();

          for (; !empty(q) && nums[q.back()] >= nums[i]; q.pop_back())
            ;

          q.push_back(i);

          if (size(q) == k)
            b.set(i);
        }

        for (int i = k - 1; i < size(nums) - k; ++i)
          if (b.test(i) && b.test(i + k))
            return true;

        return false;
      }()
           ? i
           : j) = k;
    }

    return i;
  }
};
