# Last updated: 1/15/2026, 6:15:06 PM
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        list =[]
        test = 1
        for x in range(len(nums)):
            for y in range(test, len(nums)):
                if nums[x] + nums[y] == target:
                    list.append(x)
                    list.append(y)
                    return list
            test += 1
        return list