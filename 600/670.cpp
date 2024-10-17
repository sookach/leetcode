class Solution {
public:
  int maximumSwap(int num) {
    auto s = to_string(num);

    for (auto i = begin(s); i != end(s) - 1; ++i) {
      auto j = max_element(rbegin(s), reverse_iterator(i));
      if (*j != *i) {
        iter_swap(i, j);
        break;
      }
    }

    return stoi(s);
  }
};
