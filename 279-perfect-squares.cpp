#include <queue>
#include <vector>
#include <stdexcept>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));
        vector<bool> visited(n+1, false);
        visited[n] = true;

        while (!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 1; num-i*i >= 0; i++) {
                if (num-i*i == 0) return step + 1;
                if (!visited[num-i*i]) {
                    q.push(make_pair(num-i*i, step + 1));
                    visited[num-i*i] = true;
                }
            }
        }

        throw runtime_error("should not reach here.");
    }
};

#include <iostream>

int main() {
    cout << Solution().numSquares(7168) << endl;
    return 0;
}
