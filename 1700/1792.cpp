class Solution {
public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    priority_queue q(cbegin(classes), cend(classes), [](auto &&x, auto &&y) {
      return static_cast<double>(x.front() + 1) / (x.back() + 1) -
                 static_cast<double>(x.front()) / x.back() <
             static_cast<double>(y.front() + 1) / (y.back() + 1) -
                 static_cast<double>(y.front()) / y.back();
    });
    double n = 0;

    for (; extraStudents != 0; --extraStudents) {
      auto x = q.top();
      q.pop();

      ++x.front();
      ++x.back();

      q.push(x);
    }

    for (; !empty(q); q.pop()) {
      auto x = q.top();
      n += static_cast<double>(x.front()) / x.back();
    }

    return n / size(classes);
  }
};
