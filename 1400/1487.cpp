class Solution {
public:
  vector<string> getFolderNames(vector<string> &names) {
    vector<string> v;
    unordered_map<string, int> u;

    for (auto &&x : names) {
      if (!u.contains(x)) {
        u[x] = 1;
        v.push_back(x);
        continue;
      }

      int i = u[x];
      for (; u.contains(x + '(' + to_string(i) + ')');)
        u[x] = ++i;

      v.push_back(x + '(' + to_string(i) + ')');
      u[v.back()] = 1;
      u[x] = i + 1;
    }

    return v;
  }
};
