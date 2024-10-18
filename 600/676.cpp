class MagicDictionary {
  array<vector<string>, 101> a = {};

public:
  MagicDictionary() {}

  void buildDict(vector<string> dictionary) {
    for (auto &&x : dictionary)
      a[size(x)].push_back(std::move(x));
  }

  bool search(string searchWord) {
    for (auto &&x : a[size(searchWord)]) {
      int n = 0;

      for (int i = 0; i != size(searchWord); ++i)
        n += static_cast<int>(searchWord[i] != x[i]);

      if (n == 1)
        return true;
    }

    return false;
  }
};
