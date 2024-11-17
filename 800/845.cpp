class Solution {
public:
  int longestMountain(vector<int> &arr) {
    int n = 0;

    for (int i = 1; i < size(arr) - 1; ++i) {
      auto j = i, k = i;

      for (; j > 0 && arr[j - 1] < arr[j]; --j)
        ;

      for (; k < size(arr) - 1 && arr[k + 1] < arr[k]; ++k)
        ;

      if (j != i && k != i)
        n = max(n, k - j + 1);
    }

    return n;
  }
};
