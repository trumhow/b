#include <vector>

using namespace std;

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         for (int i = 0; i < n; i++)
//             if (gas[i] >= cost[i])
//                 if (circle(gas, cost, i)) return i;
//         return -1;
//     }
// private:
//     bool circle(vector<int>& gas, vector<int>& cost, int index) {
//         int n = gas.size(), oil = 0;
//         for (int i = 0, j = index; i < n; i++) {
//             oil += gas[j];
//             if (oil < cost[j]) return false;
//             oil -= cost[j];
//             j = (j + 1) % n;
//         }
//         return true;
//     }
// };

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), start = 0, total = 0, tank = 0;
        for (int i = 0; i < n; ++i)
            if ((tank = tank + gas[i] - cost[i]) < 0) {
                start = i + 1;
                total += tank;
                tank = 0;
            }
        return (total + tank < 0) ? -1 : start;
    }
};

#include <iostream>

int main() {
    vector<int> gas{1, 2, 3, 4, 5}, cost{3, 4, 5, 1, 2};
    cout << Solution().canCompleteCircuit(gas, cost) << endl;
    return 0;
}
