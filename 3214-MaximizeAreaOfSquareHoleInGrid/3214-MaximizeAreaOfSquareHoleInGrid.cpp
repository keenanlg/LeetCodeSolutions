// Last updated: 1/15/2026, 6:15:02 PM
class Solution {
public:
    int getMaxGap(vector<int> &bars) {
        if (bars.empty()) {
            return 1;
        }

        //1. Sort the bars to find consecutive sequences
        sort(bars.begin(), bars.end());

        int maxStreak = 1;
        int currentStreak = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                //Bars are consecutive
                currentStreak++;
            }
            else {
                //Sequence broken, reset
                currentStreak = 1;
            }
            maxStreak = max(maxStreak, currentStreak);
        }

        //The gap created is the number of bars removed + 1
        return maxStreak + 1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH = getMaxGap(hBars);
        int maxV = getMaxGap(vBars);

        //For a square, we take the smaller of the two functions
        int side = min(maxH, maxV);

        return (int)(side * side);
    }
};