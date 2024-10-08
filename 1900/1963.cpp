class Solution {
public:
  int minSwaps(string s) {
    vector<int> v;
    int n = 0;

    for (int i = 0; i != size(s); ++i)
      if (s[i] == '[')
        v.push_back(i);

    for (int y = 0; auto &&x : s) {
      y += x == '[' ? 1 : -1;
      if (y < 0) {
        swap(x, s[v.back()]);
        v.pop_back();
        ++n;
        y = 1;
      }
    }

    return n;
  }
};
