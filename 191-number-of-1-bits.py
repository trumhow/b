class Solution:
    def hammingWeight(self, n: int) -> int:
        # return bin(n).count('1')
        ans = 0
        while n:
            ans += 1
            n &= n-1
        return ans


print(Solution().hammingWeight(312))
