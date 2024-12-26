class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>> &languages,
                       vector<vector<int>> &friendships) {
    array<bitset<500>, 501> a;
    int n1 = numeric_limits<int>::max();

    for (int i = 0; i != size(languages); ++i)
      for (auto &&x : languages[i])
        a[i + 1].set(x - 1);

    for (int i = 0; i != n; ++i) {
      int n2 = 0;
      bitset<500> b;

      for (auto &&x : friendships) {
        if ((a[x.front()] & a[x.back()]).any())
          continue;

        n2 += static_cast<int>(!b.test(x.front()) && !a[x.front()].test(i)) +
              static_cast<int>(!b.test(x.back()) && !a[x.back()].test(i));
        b.set(x.front());
        b.set(x.back());
      }

      n1 = min(n1, n2);
    }

    return n1;
  }
};
