class Solution {
public:
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
    priority_queue<pair<int, int>> q;

    for (int i = 0; i != size(nums); ++i)
      q.emplace(-nums[i], -i);

    for (; k != 0; --k) {
      auto [x, y] = q.top();
      q.pop();
      q.emplace(x * multiplier, y);
    }

    for (; !empty(q); q.pop()) {
      auto [x, y] = q.top();
      nums[-y] = -x;
    }

    return nums;
  }
};
