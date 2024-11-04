class Solution {
public:
  string compressedString(string word) {
    string s;
    int n = 0;

    for (auto y = word.front(); auto &&x : word) {
      if (n == 9 || x != y) {
        s += to_string(n) + y;
        n = 0;
      }

      y = x;
      ++n;
    }

    return s + to_string(n) + word.back();
  }
};
