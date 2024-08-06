#include <algorithm>
#include <array>
#include <atomic>
#include <bit>
#include <bitset>
#include <chrono>
#include <deque>
#include <execution>
#include <format>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numbers>
#include <queue>
#include <random>
#include <ranges>
#include <regex>
#include <set>
#include <span>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <utility>

#ifndef LIST_NODE
#define LIST_NODE

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif

#ifndef LIST_NODE
#define LIST_NODE

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#endif

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#ifndef NODE_DEF_
#define NODE_DEF_

// Definition for a Node.
class Node {
public:
  int val;
  std::vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

#endif

#ifndef NODE_DEF_
#define NODE_DEF_

// Definition for a Node.
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

#endif

#ifndef NODE_DEF_
#define NODE_DEF_

// Definition for a Node.
class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

#endif

//  Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  struct Data;
  Data *data;

public:
  Iterator(const std::vector<int> &nums);
  Iterator(const Iterator &iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

template <typename T, typename U>
std::ostream &operator<<(std::ostream &, const std::pair<T, U> &);

template <typename T>
std::ostream &operator<<(std::ostream &, const std::vector<T> &);

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &a) {
  if (std::empty(a))
    return os << "[]";

  for (os << '['; const auto &x : a)
    os << x << ',';

  return os << '\b' << ']';
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  if (std::empty(v))
    return os << "[]";

  for (os << '['; const auto &x : v)
    os << x << ',';

  return os << '\b' << ']';
}

std::ostream &operator<<(std::ostream &os_, const std::vector<bool> &v_) {
  if (std::empty(v_))
    return os_ << "[]";

  for (os_ << "[" << std::boolalpha; auto &&x : v_)
    os_ << x << ',';

  return os_ << std::noboolalpha << "\b]";
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
  return os << '[' << p.first << ' ' << p.second << ']';
}

std::ostream &operator<<(std::ostream &os_, const ListNode *n_) {
  if (n_ == nullptr)
    return os_ << "[]";

  os_ << '[';

  for (; n_ != nullptr; n_ = n_->next)
    os_ << n_->val << ',';

  return os_ << "\b]";
}

ListNode *make_list(std::span<int> s_ = {}) {
  if (std::empty(s_))
    return nullptr;

  auto n{new ListNode{s_.front()}};
  n->next = make_list(s_.subspan(1));

  return n;
}

ListNode *make_list(auto &&x, auto &&...y) {
  if constexpr (sizeof...(y) == 0)
    return new ListNode{x};
  else
    return new ListNode{x, make_list(std::forward<decltype(y)>(y)...)};
}

TreeNode *make_tree(std::span<std::string> s, int i = 0) {
  if (i >= std::size(s) || s[i] == "null")
    return nullptr;

  auto t{new TreeNode{std::stoi(s[i])}};
  t->left = make_tree(s, i * 2 + 1);
  t->right = make_tree(s, i * 2 + 2);

  return t;
}

TreeNode *make_tree(std::span<int> s, int i = 0) {
  if (i >= std::size(s) || s[i] == 0)
    return nullptr;

  auto t{new TreeNode{s[i]}};
  t->left = make_tree(s, i * 2 + 1);
  t->right = make_tree(s, i * 2 + 2);

  return t;
}

std::ostream &operator<<(std::ostream &os_, const TreeNode *n_) {
  for (std::deque d{n_}; !std::empty(d); os_ << '\n') {
    for (auto n{std::size(d)}; n > 0; --n) {
      os_ << (d.front() == nullptr ? "n "
                                   : std::to_string(d.front()->val) + " ");
      if (d.front() != nullptr)
        d.push_back(d.front()->left), d.push_back(d.front()->right);
      d.pop_front();
    }
  }

  return os_;
}

template <typename T> struct recursive final {
  const T F;

  constexpr recursive(T &&F) : F(std::forward<T>(F)) {}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args &&...A) const noexcept {
    return F(std::cref(*this), std::forward<Args>(A)...);
  }
};

inline static constexpr struct {
  constexpr decltype(auto) operator()(auto &&fn,
                                      auto &&...args) const noexcept {
    return recursive{std::forward<decltype(fn)>(fn)}(
        std::forward<decltype(args)>(args)...);
  }
} recurse{};

inline static constexpr struct {
  std::vector<std::string> operator()(std::string &&s,
                                      char delim = ' ') const noexcept {
    std::vector<std::string> v{};

    auto first{std::move_iterator{std::cbegin(s)}},
        last{std::move_iterator{std::cend(s)}};

    for (;;) {
      first = std::find_if(first, last,
                           [delim](auto &&x) -> bool { return x != delim; });

      if (first == last)
        break;

      auto next{std::find(first, last, delim)};
      v.emplace_back(first, next);

      if (next == last)
        break;

      first = next + 1;
    }

    return v;
  }
} split{};

inline static constexpr struct {
  using point = std::pair<int, int>;
  using vec = std::pair<int, int>;

  constexpr int operator()(point a, point b, point c) const noexcept {
    return this->operator()({b.first - a.first, b.second - a.second},
                            {c.first - b.first, c.second - b.second});
  }

  constexpr int operator()(vec a, vec b) const noexcept {
    return a.first * b.second - a.second * b.first;
  }
} cross_product{};

template <size_t N> struct union_find final {
  std::array<int, N> p{}, r{};

  constexpr union_find() { iota(begin(p), end(p), 0); }

  constexpr int find(int i) noexcept {
    return p[i] == i ? i : p[i] = find(p[i]);
  }

  constexpr void unite(int i, int j) noexcept {
    auto x{find(i)}, y{find(j)};

    if (r[x] < r[y])
      swap(x, y);

    r[x] += static_cast<int>(r[x] == r[y]);

    p[y] = x;
  }
};

template <size_t N> struct fenwick final {
  std::array<int, N> a = {};

  constexpr void add(int i, int x) noexcept {
    for (; i < N; i += i & -i)
      a[i] += x;
  }

  constexpr int find(int i) noexcept {
    int x = 0;
    for (; i != 0; i -= i & -i)
      x += a[i];
    return x;
  }
};
