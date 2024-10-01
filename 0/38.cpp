class Solution {
public:
  string countAndSay(int n) {
    string s = "1";
    for (int i = 1; i != n; ++i) {
      string t;
      for (int i = 0; i != size(s);) {
        int j = i + 1;
        for (; j != size(s) && s[i] == s[j]; ++j)
          ;
        t.push_back(j - i + '0');
        t.push_back(s[i]);
        i = j;
      }
      s = t;
    }
    return s;
  }
};

