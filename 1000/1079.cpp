class Solution {
public:
  int numTilePossibilities(string tiles) {
    unordered_set<string> u;
    bitset<8> b = 1;

    for (; b.to_ulong() != 1 << size(tiles); b = b.to_ulong() + 1) {
      string s;
      for (int i = 0; i != size(tiles); ++i)
        if (b.test(i))
          s.push_back(tiles[i]);

      ranges::sort(s);

      do
        u.insert(s);
      while (ranges::next_permutation(s).found);
    }

    return size(u);
  }
};
