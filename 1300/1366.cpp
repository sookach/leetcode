class Solution {
public:
  string rankTeams(vector<string> &votes) {
    array<array<int, 26>, 26> a = {};
    bitset<26> b;
    string s;

    for (auto &&x : votes) {
      for (int i = 0; i != size(x); ++i) {
        ++a[i][x[i] - 'A'];
        b.set(x[i] - 'A');
      }
    }

    for (int i = 0; i != 26; ++i)
      if (b.test(i))
        s.push_back(i + 'A');

    ranges::sort(s, [&](auto &&x, auto &&y) {
      for (auto &&r : a) {
        if (r[x - 'A'] > r[y - 'A'])
          return true;
        if (r[x - 'A'] < r[y - 'A'])
          return false;
      }
      return x < y;
    });

    return s;
  }
};
