template <typename T> struct recursive final {
  const T F;

  constexpr recursive(T &&F) : F(std::forward<T>(F)) {}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args &&...A) const noexcept {
    return F(std::cref(*this), std::forward<Args>(A)...);
  }
};

class ThroneInheritance {
  unordered_map<string, vector<string>> u1;
  unordered_set<string> u2;
  string s;

public:
  ThroneInheritance(string kingName) : s(std::move(kingName)) {}

  void birth(string parentName, string childName) {
    u1[std::move(parentName)].push_back(std::move(childName));
  }

  void death(string name) { u2.insert(std::move(name)); }

  vector<string> getInheritanceOrder() {
    vector<string> v;

    recursive([&](auto &&self, auto &&s) -> void {
      if (!u2.contains(s))
        v.push_back(s);
      for (auto &&x : u1[s])
        self(x);
    })(s);

    return v;
  }
};
