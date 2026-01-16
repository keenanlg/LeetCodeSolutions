// Last updated: 1/16/2026, 6:07:45 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //Iterate from the last digit to the first
        for (int i = digits.size() - 1; i >= 0; i--) {
            //Increment the last digit
            digits[i]++;

            //If the digit is less than 10, solution is found
            if (digits[i] < 10) {
                return digits;
            }

            /*If the digit reached 10, set to 0 and continue 
            loop to increment the next digit*/
            digits[i] = 0;
        }

        //This runs if all digits are 9 and an extra digit is needed
        digits.insert(digits.begin(), 1);

        return digits;
    }
};