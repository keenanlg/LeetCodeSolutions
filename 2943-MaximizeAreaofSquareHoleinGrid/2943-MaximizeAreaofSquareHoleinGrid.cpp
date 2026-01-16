// Last updated: 1/16/2026, 6:07:35 PM
1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4        //Iterate from the last digit to the first
5        for (int i = digits.size() - 1; i >= 0; i--) {
6            //Increment the last digit
7            digits[i]++;
8
9            //If the digit is less than 10, solution is found
10            if (digits[i] < 10) {
11                return digits;
12            }
13
14            /*If the digit reached 10, set to 0 and continue 
15            loop to increment the next digit*/
16            digits[i] = 0;
17        }
18
19        //This runs if all digits are 9 and an extra digit is needed
20        digits.insert(digits.begin(), 1);
21
22        return digits;
23    }
24};