#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (auto c : s) {
            switch (c) {
                case '(': { stack.push(')'); break; }
                case '[': { stack.push(']'); break; }
                case '{': { stack.push('}'); break; }
                default: {
                    if (stack.empty() || stack.top() != c) return false;
                    stack.pop();
                }
            }
        }
        return stack.empty();
    }
};

#include <iostream>

int main() {
    cout << Solution().isValid("()[]{}") << endl;
    // string str("()[]{}");
    // for (auto c : str) {
    //     switch (c) {
    //         case '(': { cout << '(' << endl; break; }
    //         case '[': { cout << '[' << endl; break; }
    //         case '{': { cout << '{' << endl; break; }
    //         default: {
    //             cout << "default" << endl;
    //         }
    //     }
    // }
    return 0;
}
