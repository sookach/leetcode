class RLEIterator {
  vector<pair<int, int>> v;

public:
  RLEIterator(vector<int> &encoding) {
    for (int i = 0; i != size(encoding); i += 2)
      if (encoding[i] != 0)
        v.emplace_back(encoding[i], encoding[i + 1]);
    ranges::reverse(v);
  }

  int next(int n) {
    int x = -1;

    for (; !empty(v) && n != 0;) {
      auto y = min(n, v.back().first);
      n -= y;
      x = v.back().second;
      if ((v.back().first -= y) == 0)
        v.pop_back();
    }

    return n != 0 ? -1 : x;
  }
};
