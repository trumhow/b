class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n != 0 and (n & n-1) == 0


print(Solution().isPowerOfTwo(17))
