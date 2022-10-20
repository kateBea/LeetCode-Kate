class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        midle = (left + right) // 2
        
        while left <= right:
            if nums[midle] > target:
                right = midle - 1
            elif nums[midle] < target:
                left = midle + 1
            else:
                return midle
            
            midle = (left + right) // 2
            
        return left