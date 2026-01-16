// Last updated: 1/16/2026, 4:56:32 PM
1class Solution {
2public:
3    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
4        //Add the boundary fences (1, m) and (1, n) which cannot be removed
5        hFences.push_back(1);
6        hFences.push_back(m);
7        vFences.push_back(1);
8        vFences.push_back(n);
9
10        //Calculate all possible horizontal distances
11        unordered_set<int> hDistances;
12        for (int i = 0; i < hFences.size(); i++) {
13            for (int j = i + 1; j < hFences.size(); j++) {
14                hDistances.insert(abs(hFences[i] - hFences[j]));
15            }
16        }
17
18        //Find the maximum distance that also exists vertically
19        int maxSide = -1;
20        for (int i = 0; i < vFences.size(); i++) {
21            for (int j = i + 1; j < vFences.size(); j++) {
22                int d = abs(vFences[i] - vFences[j]);
23                if (hDistances.count(d)) {
24                    maxSide = max(maxSide, d);
25                }
26            }
27        }
28
29        //Return -1 if no square is possible
30        if (maxSide == -1) {
31            return -1;
32        }
33
34        //Calculate area with modulo
35        long long mod = 1e9 + 7;
36        return (int)((1LL * maxSide * maxSide) % mod);
37    }
38};