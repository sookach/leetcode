class Solution {
public:
  string addSpaces(string s, vector<int> &spaces) {
    string t;

    for (int i = 0, j = 0; i != size(s); ++i) {
      if (j != size(spaces) && i == spaces[j]) {
        ++j;
        t.push_back(' ');
      }
      t.push_back(s[i]);
    }

    return t;
  }
};

