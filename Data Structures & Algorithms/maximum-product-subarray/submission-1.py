class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # dp[i] represents theargest product
        # subarray you can get if the shbarray ends at i
        dp_min = [0] * len(nums)
        dp_max = [0] * len(nums)
        for i in range(len(nums)):
            prev_max = dp_max[i-1] * nums[i] if i>0 else nums[i]
            prev_min = dp_min[i-1] * nums[i] if i>0 else nums[i]
            dp_max[i] = max(prev_max, prev_min, nums[i])
            dp_min[i] = min(prev_max, prev_min, nums[i])

        return max(max(dp_max), max(dp_min))