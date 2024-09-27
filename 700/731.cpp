class MyCalendarTwo {
  map<int, int> m;

public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    ++m[start];
    --m[end];

    for (int i = 0; auto &&[x, y] : m) {
      if (i += y; i > 2) {
        --m[start];
        ++m[end];
        return false;
      }
    }

    return true;
  }
};

