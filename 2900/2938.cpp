class Solution {
public:
  long long minimumSteps(string s) {
    priority_queue<int> q;
    long long n = 0;

    for (int i = 0; i != size(s); ++i) {
      if (s[i] == '0') {
        if (empty(q))
          continue;
        n += i + q.top();
        q.pop();
        q.push(-i);
      } else {
        q.push(-i);
      }
    }

    return n;
  }
};
