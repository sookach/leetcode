class TopVotedCandidate {
  vector<pair<int, int>> v;

public:
  TopVotedCandidate(vector<int> &persons, vector<int> &times) {
    array<int, 5'000> a = {};
    int x = -1, y = -1;

    for (int i = 0; i != size(persons); ++i) {
      if (++a[persons[i]] >= y) {
        x = persons[i];
        y = a[persons[i]];
      }

      v.emplace_back(times[i], x);
    }
  }

  int q(int t) {
    auto i = ranges::lower_bound(v, t, {}, &pair<int, int>::first);

    if (i == cend(v))
      return v.back().second;

    for (; i->first > t; --i)
      ;

    return i->second;
  }
};
