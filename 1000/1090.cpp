class Solution {
public:
  int largestValsFromLabels(vector<int> &values, vector<int> &labels,
                            int numWanted, int useLimit) {
    array<int, 20'001> a = {};
    priority_queue<pair<int, int>> q;
    int n = 0;

    for (int i = 0; i != size(values); ++i)
      q.emplace(values[i], labels[i]);

    for (int i = 0; !empty(q) && i != numWanted;) {
      auto [x, y] = q.top();
      q.pop();

      if (a[y]++ >= useLimit)
        continue;

      n += x;
      ++i;
    }

    return n;
  }
};
