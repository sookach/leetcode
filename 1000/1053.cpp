class Solution {
public:
  vector<int> prevPermOpt1(vector<int> &arr) {
    int i = size(arr) - 2, x = arr.back();

    for (; i != -1 && arr[i] <= x; --i)
      x = min(x, arr[i]);

    if (i != -1) {
      auto j = find_if(begin(arr) + i, end(arr),
                       [&](auto &&x) { return x < arr[i]; });
      for (auto k = j;
           (k = find_if(begin(arr) + i, end(arr),
                        [&](auto &&x) { return x > *j && x < arr[i]; })) !=
           cend(arr);
           j = k)
        ;
      iter_swap(begin(arr) + i, j);
    }

    return arr;
  }
};
