struct trie final {
  struct node final {
    std::array<node *, 26> a = {};
  };

  node *t = new node;

  void insert(std::string_view s) {
    for (node *n = t; auto &&x : s) {
      if (n->a[x - 'a'] == nullptr)
        n->a[x - 'a'] = new node;
      n = n->a[x - 'a'];
    }
  }

  bool contains(std::string_view s) {
    for (node *n = t; auto &&x : s) {
      if (n->a[x - 'a'] == nullptr)
        return false;
      n = n->a[x - 'a'];
    }
    return true;
  }
};

class Solution {
public:
  int minValidStrings(vector<string> &words, string target) {
    trie t;
    array<int, 5'001> a = {};

    ranges::fill(a, numeric_limits<int>::max());
    a.front() = 0;

    for (auto &&x : words)
      t.insert(x);

    for (int i = 0; i != size(target); ++i) {
      if (a[i] == numeric_limits<int>::max())
        continue;
      auto n = t.t;
      for (int j = i; j != size(target); ++j) {
        if (n->a[target[j] - 'a'] == nullptr)
          break;
        n = n->a[target[j] - 'a'];
        a[j + 1] = min(a[j + 1], a[i] + 1);
      }
    }

    return a[size(target)] == numeric_limits<int>::max() ? -1 : a[size(target)];
  }
};
