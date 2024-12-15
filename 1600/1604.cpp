class Solution {
public:
  vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime) {
    unordered_map<string, vector<int>> u;
    vector<string> v;

    for (int i = 0; i != size(keyName); ++i)
      u[keyName[i]].push_back(stoi(keyTime[i].substr(0, 2)) * 60 +
                              stoi(keyTime[i].substr(3)));

    for (auto &&[x, y] : u) {
      ranges::sort(y);

      for (int i = 0, j = 0; j != size(y); ++j) {
        for (; y[j] - y[i] > 60; ++i)
          ;
        if (j - i > 1) {
          v.push_back(x);
          break;
        }
      }
    }

    ranges::sort(v);
    return v;
  }
};
