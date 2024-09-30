
struct trie final {
  struct node final {
    std::array<node *, 2> a = {};
  };

  node *t = new node;

  void insert(unsigned x) {
    std::bitset<32> b(x);
    node *n = t;

    for (int i = 31; i != -1; --i) {
      if (n->a[b.test(i)] == nullptr)
        n->a[b.test(i)] = new node;
      n = n->a[b.test(i)];
    }
  }

  unsigned search(unsigned x) {
    std::bitset<32> b(x);
    node *n = t;
    x = 0;

    for (int i = 31; i != -1; --i) {
      if (n->a[!b.test(i)]) {
        x += 1 << i;
        n = n->a[!b.test(i)];
      } else {
        n = n->a[b.test(i)];
      }
    }

    return x;
  }
};

class Solution {
public:
  int findMaximumXOR(vector<int> &nums) {
    trie t;
    unsigned y = 0;

    for (auto &&x : nums) {
      t.insert(x);
      y = max(y, t.search(x));
    }

    return y;
  }
};
