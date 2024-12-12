class Solution {
public:
  long long pickGifts(vector<int> &gifts, int k) {
    priority_queue q(cbegin(gifts), cend(gifts));
    long long n = 0;

    for (; k != 0; --k) {
      auto x = q.top();
      q.pop();
      q.push(sqrt(x));
    }

    for (; !empty(q); q.pop())
      n += q.top();

    return n;
  }
};
