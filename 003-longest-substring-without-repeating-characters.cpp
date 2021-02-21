#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastOccurred;
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            auto it = lastOccurred.find(s[i]);
            if (it != lastOccurred.end() && it->second >= start) {
                start = it->second + 1;
            }
            maxLen = max(maxLen, i-start+1);
            lastOccurred[s[i]] = i;
        }
        return maxLen;
    }
};

#include <iostream>

int main()
{
    cout << Solution().lengthOfLongestSubstring("abcabc") << endl;
    cout << Solution().lengthOfLongestSubstring(" ") << endl;
    cout << Solution().lengthOfLongestSubstring("z") << endl;
    cout << Solution().lengthOfLongestSubstring("abcdef") << endl;

    std::u32string us(U"黑化肥挥发发灰会花飞,灰化肥挥发发黑会飞花");
    cout << us.size() << endl;

    return 0;
}
