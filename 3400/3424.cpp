class Solution {
public:
  long long minCost(vector<int> &arr, vector<int> &brr, long long k) {
    long long n1 = 0, n2 = 0;

    for (int i = 0; i != size(arr); ++i)
      n1 += abs(arr[i] - brr[i]);

    ranges::sort(arr);
    ranges::sort(brr);

    for (int i = 0; i != size(arr); ++i)
      n2 += abs(arr[i] - brr[i]);

    return min(n1, n2 + k);
  }
};
