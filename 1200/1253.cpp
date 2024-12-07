class Solution {
public:
  vector<vector<int>> reconstructMatrix(int upper, int lower,
                                        vector<int> &colsum) {
    vector<vector<int>> v(2);

    for (auto &&x : colsum) {
      switch (x) {
      default:
        v.front().push_back(0);
        v.back().push_back(0);
        break;
      case 1:
        if (upper == 0 && lower == 0)
          return {};

        if (upper > lower) {
          --upper;
          v.front().push_back(1);
          v.back().push_back(0);
        } else {
          --lower;
          v.front().push_back(0);
          v.back().push_back(1);
        }
        break;
      case 2:
        if (upper == 0 || lower == 0)
          return {};
        v.front().push_back(1);
        v.back().push_back(1);
        --upper;
        --lower;
      }
    }

    if (upper != 0 || lower != 0)
      return {};

    return v;
  }
};
