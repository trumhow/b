#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q(queue<string>::container_type(1, beginWord));
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            for (size_t i = 0; i < word.size(); i++) {
                char c = word[i];
                for (int j = 0; j < 26; j++) {
                    word[i] = 'a' + j;
                    if (dict.find(word) != dict.end()) {
                        if (word == endWord) {
                            ans.push_back({"", ""});
                        }
                    }
                }
                word[i] = c;
            }
        }
        return ans;
    }
};

#include <iostream>

int main() {
    queue<string> q(queue<string>::container_type(1, "222"));
    cout << q.front() << endl;
    return 0;
}
