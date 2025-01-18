class Solution {
public:
  int minMaxWeight(int n, vector<vector<int>> &edges, int threshold) {
    array<vector<pair<int, int>>, 100'000> a;
    priority_queue<pair<int, int>> q;
    bitset<100'000> b;
    int d = 0;

    for (auto &&x : edges) {
      a[x[1]].emplace_back(x.front(), x.back());
    }

    q.emplace(0, 0);

    for (; !empty(q);) {
      auto [x, i] = q.top();
      q.pop();

      if (b.test(i))
        continue;
      b.set(i);

      d = min(d, x);

      for (auto &&[v, e] : a[i])
        q.emplace(min(d, -e), v);
    }

    return b.count() == n ? -d : -1;
  }
};
