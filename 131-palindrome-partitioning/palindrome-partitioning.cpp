class Solution {
public:
    vector<vector<string>> partition(string s) {
        int length = s.size();
        vector<vector<bool>> isPalindrome(length, vector<bool>(length, false));
        
        fillPalindromeTable(s, isPalindrome);
        
        vector<vector<string>> allPartitions;
        generatePartitions(s, 0, isPalindrome, {}, allPartitions);
        return allPartitions;
    }

private:
    void fillPalindromeTable(const string& s, vector<vector<bool>>& isPalindrome) {
        int length = s.size();
        for (int start = length - 1; start >= 0; --start) {
            for (int end = start; end < length; ++end) {
                if (s[start] == s[end]) {
                    if (end - start < 3) {
                        isPalindrome[start][end] = true;
                    } else {
                        isPalindrome[start][end] = isPalindrome[start + 1][end - 1];
                    }
                }
            }
        }
    }

    void generatePartitions(const string& s, int start, const vector<vector<bool>>& isPalindrome, vector<string> currentPartition, vector<vector<string>>& allPartitions) {
        if (start == s.size()) {
            allPartitions.push_back(currentPartition);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome[start][end]) {
                currentPartition.push_back(s.substr(start, end - start + 1));
                generatePartitions(s, end + 1, isPalindrome, currentPartition, allPartitions);
                currentPartition.pop_back();  // Backtrack
            }
        }
    }
};