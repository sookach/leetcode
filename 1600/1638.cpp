class Solution {
public:
  int countSubstrings(string s, string t) {
    int n = 0;

    for (int i = 0; i != size(s); ++i) {
      for (int j = 0; j != size(t); ++j) {
        for (int k = 0, x = 0; i + k != size(s) && j + k != size(t); ++k) {
          switch (x += static_cast<int>(s[i + k] != t[j + k])) {
          default:
            break;
          case 1:
            ++n;
            break;
          case 2:
            goto done;
          }
        }
      done:
      }
    }

    return n;
  }
};
