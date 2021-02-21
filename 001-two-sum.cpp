#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> record;
//         for (int i = 0; i < nums.size(); i++) {
//             auto it = record.find(target - nums[i]);
//             if (it != record.end()) {
//                 return {it->second, i};
//             }
//             record[nums[i]] = i;
//         }
//         assert(false);
//     }
// };

// #include <iostream>

// int main()
// {
//     assert(false);
//     return 0;
// }
