class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (size(s2) < size(s1))
      return false;
      
    array<int, 26> a = {};

    for (int i = 0; i != size(s1); ++i) {
      ++a[s1[i] - 'a'];
      --a[s2[i] - 'a'];
    }

    if (ranges::all_of(a, [](auto &&x) { return x == 0; }))
      return true;

    for (int i = size(s1); i != size(s2); ++i) {
      ++a[s2[i - size(s1)] - 'a'];
      --a[s2[i] - 'a'];
      if (ranges::all_of(a, [](auto &&x) { return x == 0; }))
        return true;
    }

    return false;
  }
};
