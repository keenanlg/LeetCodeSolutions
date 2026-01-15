# Last updated: 1/15/2026, 6:15:04 PM
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        roman_map = {
        'I': 1, 'V': 5, 'X': 10, 'L': 50,
        'C': 100, 'D': 500, 'M': 1000
        }
        
        total = 0
        i = 0
        
        while i < len(s):
            current_val = roman_map[s[i]]
            
            if i + 1 < len(s):
                next_val = roman_map[s[i+1]]
                if current_val < next_val:
                    total += (next_val - current_val)
                    i += 2
                    continue
            
            total += current_val
            i += 1
            
        return total