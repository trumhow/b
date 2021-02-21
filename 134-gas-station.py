from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        for i in range(len(gas)):
            if gas[i] >= cost[i]:
                if Solution._circle(self, gas, cost, i):
                    return i
        return -1

    def _circle(self, gas: List[int], cost: List[int], index: int) -> bool:
        n, j, oil = len(gas), index, 0
        for i in range(n):
            oil += gas[j]
            if oil < cost[j]:
                return False
            oil -= cost[j]
            j = (j + 1) % n
        return True


print(Solution().canCompleteCircuit([1, 2, 3, 4, 5], [3, 4, 5, 1, 2]))
