// Last updated: 1/16/2026, 4:56:55 PM
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        //Add the boundary fences (1, m) and (1, n) which cannot be removed
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        //Calculate all possible horizontal distances
        unordered_set<int> hDistances;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDistances.insert(abs(hFences[i] - hFences[j]));
            }
        }

        //Find the maximum distance that also exists vertically
        int maxSide = -1;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int d = abs(vFences[i] - vFences[j]);
                if (hDistances.count(d)) {
                    maxSide = max(maxSide, d);
                }
            }
        }

        //Return -1 if no square is possible
        if (maxSide == -1) {
            return -1;
        }

        //Calculate area with modulo
        long long mod = 1e9 + 7;
        return (int)((1LL * maxSide * maxSide) % mod);
    }
};