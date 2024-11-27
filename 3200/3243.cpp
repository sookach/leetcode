class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>> &queries) {
    array<vector<int>, 500> a;
    auto f = [&] {
      bitset<500> b;
      deque q = {0};

      b.set(0);

      for (int x = 0;; ++x) {
        for (auto y = size(q); y != 0; --y) {
          auto i = q.front();
          q.pop_front();

          if (i == n - 1)
            return x;

          for (auto &&x : a[i]) {
            if (!b.test(x)) {
              b.set(x);
              q.push_back(x);
            }
          }
        }
      }

      return -1;
    };
    vector<int> v;

    for (int i = 0; i != n - 1; ++i)
      a[i].push_back(i + 1);

    for (auto &&x : queries) {
      a[x.front()].push_back(x.back());
      v.push_back(f());
    }

    return v;
  }
};
