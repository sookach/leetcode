class Solution {
public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if (clamp(tomatoSlices, cheeseSlices * 2, cheeseSlices * 4) !=
            tomatoSlices ||
        tomatoSlices % 2 != 0)
      return {};
    return {(tomatoSlices - 2 * cheeseSlices) / 2,
            cheeseSlices - (tomatoSlices - 2 * cheeseSlices) / 2};
  }
};
