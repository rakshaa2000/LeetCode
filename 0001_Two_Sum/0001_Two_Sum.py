class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i=0
        l=[]
        while(i<len(nums)):
            if target-nums[i] in nums:
                l.append(i)
                l.append(nums.index(target-nums[i]))
            i+=1
        l=list(set(l))
        return l
