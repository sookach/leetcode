class Solution {
public:
  int minimumDiameterAfterMerge(vector<vector<int>> &edges1,
                                vector<vector<int>> &edges2) {
    auto f = [](int i, auto &&a) {
      bitset<100'000> b;
      int n = -1;
      b.set(i);

      for (deque q = {i}; !empty(q); ++n) {
        i = q.front();
        for (auto x = size(q); x != 0; --x) {
          for (auto &&y : a[q.front()]) {
            if (!b.test(y)) {
              b.set(y);
              q.push_back(y);
            }
          }
          q.pop_front();
        }
      }

      return pair(i, n);
    };
    array<vector<int>, 100'000> a1, a2;

    for (auto &&x : edges1) {
      a1[x.front()].push_back(x.back());
      a1[x.back()].push_back(x.front());
    }

    for (auto &&x : edges2) {
      a2[x.front()].push_back(x.back());
      a2[x.back()].push_back(x.front());
    }

    auto n1 = f(f(0, a1).first, a1).second, n2 = f(f(0, a2).first, a2).second;
    return max({n1, n2, (n1 + 1) / 2 + (n2 + 1) / 2 + 1});
  }
};
