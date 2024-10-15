class ExamRoom {
  set<int> s;
  int n;

public:
  ExamRoom(int n) : n(n) {}

  int seat() {
    if (empty(s)) {
      s.insert(0);
      return 0;
    }

    auto x = 0, y = *cbegin(s);

    for (auto i = cbegin(s); i != prev(cend(s)); ++i) {
      if ((*next(i) - *i) / 2 > y) {
        y = (*next(i) - *i) / 2;
        x = *i + y;
      }
    }

    if (n - 1 - *crbegin(s) > y)
      x = n - 1;

    s.insert(x);
    return x;
  }

  void leave(int p) { s.erase(p); }
};
