#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return {}; // If endWord is not in wordList, return empty.

        // BFS setup
        unordered_map<string, vector<string>> parents; // To track parents for path reconstruction.
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> currentLevelVisited;
        bool foundEndWord = false;

        while (!q.empty() && !foundEndWord) {
            int levelSize = q.size();
            currentLevelVisited.clear();

            for (int i = 0; i < levelSize; i++) {
                string word = q.front();
                q.pop();

                string originalWord = word;
                for (int j = 0; j < word.size(); j++) {
                    char originalChar = word[j];

                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        if (wordSet.find(word) != wordSet.end()) {
                            // Found the endWord
                            if (word == endWord) {
                                foundEndWord = true;
                            }

                            // Record the parent relationship
                            parents[word].push_back(originalWord);

                            // Add to queue only if not already visited
                            if (currentLevelVisited.find(word) == currentLevelVisited.end()) {
                                q.push(word);
                                currentLevelVisited.insert(word);
                            }
                        }
                    }
                    word[j] = originalChar; // Restore the original character
                }
            }

            // Remove words that are processed in this level
            for (const auto& word : currentLevelVisited) {
                wordSet.erase(word);
            }
        }

        // If endWord is not reached, return an empty result
        if (!foundEndWord) return {};

        // Reconstruct paths from endWord to beginWord
        vector<vector<string>> results;
        vector<string> path;
        dfs(endWord, beginWord, parents, path, results);
        return results;
    }

private:
    void dfs(const string& word, const string& beginWord, unordered_map<string, vector<string>>& parents,
             vector<string>& path, vector<vector<string>>& results) {
        path.push_back(word);

        if (word == beginWord) {
            results.push_back(vector<string>(path.rbegin(), path.rend()));
        } else {
            for (const auto& parent : parents[word]) {
                dfs(parent, beginWord, parents, path, results);
            }
        }

        path.pop_back();
    }
};
