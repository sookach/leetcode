class Solution {
public:
  int findLengthOfShortestSubarray(vector<int> &arr) {
    bitset<100'000> b1, b2;

    b1.set(0);
    b2.set(size(arr) - 1);

    for (int i = 1; i != size(arr) && arr[i] >= arr[i - 1]; ++i)
      b1.set(i);

    for (int i = size(arr) - 2; i != -1 && arr[i] <= arr[i + 1]; --i)
      b2.set(i);

    int i = -1, j = size(arr) - 1;
    for (; i != j - 1;) {
      ([&](auto &&x) {
        if (b2.test(x) || b1.test(size(arr) - x - 1))
          return true;

        for (int i = 0; i != size(arr) - x - 1; ++i)
          if (b1.test(i) && b2.test(i + x + 1) && arr[i] <= arr[i + x + 1])
            return true;

        return false;
      }(i + (j - i) / 2)
           ? j
           : i) = i + (j - i) / 2;
    }

    return j;
  }
};
