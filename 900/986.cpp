class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                           vector<vector<int>> &secondList) {
    vector<vector<int>> v;

    for (int i = 0, j = 0; i != size(firstList) && j != size(secondList);) {
      auto [x, y] = minmax(firstList[i], secondList[j]);

      if (x.back() < y.front())
        goto skip;

      if (y.front() <= x.back() && y.back() <= x.back())
        v.push_back(y);
      else
        v.push_back({y.front(), x.back()});

    skip:
      ++(firstList[i].back() < secondList[j].back() ? i : j);
    }

    return v;
  }
};
