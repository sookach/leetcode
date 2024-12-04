class Solution {
public:
  bool canMakeSubsequence(string str1, string str2) {
    int j = 0;
    
    for (int i = 0; i != size(str1) && j != size(str2); ++i)
      j += static_cast<int>(str1[i] == str2[j] ||
                            (str1[i] - 'a' + 1) % 26 + 'a' == str2[j]);

    return j == size(str2);
  }
};
