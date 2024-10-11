class Solution {
public:
  int smallestChair(vector<vector<int>> &times, int targetFriend) {
    array<vector<int>, 100'001> a = {};
    priority_queue<int> q;
    auto x = times[targetFriend].front();

    ranges::sort(times);

    for (int i = 0; i != size(times); ++i)
      q.push(-i);

    for (int i = 0, j = 0;; ++i) {
      for (auto &&x : a[i])
        q.push(x);

      if (i == x)
        break;

      if (i == times[j].front()) {
        a[times[j].back()].push_back(q.top());
        q.pop();
        ++j;
      }
    }

    return -q.top();
  }
};
