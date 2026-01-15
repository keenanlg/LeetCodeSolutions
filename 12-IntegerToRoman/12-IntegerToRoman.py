# Last updated: 1/15/2026, 6:15:04 PM
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """

        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        romanValues = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]

        result = ""
        iterator = 0
        num += 1

        for val in values:
            if val < num:
                while ((num - val) > 0):
                    num -= val
                    result += romanValues[iterator]
            iterator += 1

        return result
        