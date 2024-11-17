class Solution {
public:
  string findReplaceString(string s, vector<int> &indices,
                           vector<string> &sources, vector<string> &targets) {
    array<pair<string, int>, 1'000> a;
    string t;

    for (int i = 0; i != size(sources); ++i)
      if (sources[i] == s.substr(indices[i], size(sources[i])))
        a[indices[i]] = {targets[i], size(sources[i])};

    for (int i = 0; i != size(s);) {
      if (a[i].second == 0) {
        t.push_back(s[i++]);
      } else {
        t += a[i].first;
        i += a[i].second;
      }
    }

    return t;
  }
};
