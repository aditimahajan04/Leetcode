class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        // Length of each word and total length of concatenated words
        int wordLength = words[0].size();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;

        // Reference map to store word frequencies
        unordered_map<string, int> wordFreq;
        for (const string& word : words) 
            wordFreq[word]++;

        // Iterate over each possible offset (from 0 to wordLength - 1)
        for (int offset = 0; offset < wordLength; ++offset) {
            unordered_map<string, int> seen;
            int left = offset, count = 0;

            // Sliding window loop
            for (int right = offset; right + wordLength <= s.size(); right += wordLength) {
                string word = s.substr(right, wordLength);

                // If the word exists in the reference map
                if (wordFreq.count(word)) {
                    seen[word]++;
                    count++;

                    // Shrink the window if the word occurs too many times
                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seen[leftWord]--;
                        count--;
                        left += wordLength;
                    }

                    // If the window matches the total length of concatenated words
                    if (count == wordCount) 
                        result.push_back(left);
                } 
                // If the word does not exist, reset the sliding window
                else {
                    seen.clear();
                    count = 0;
                    left = right + wordLength;
                }
            }
        }
        return result;
    }
};
