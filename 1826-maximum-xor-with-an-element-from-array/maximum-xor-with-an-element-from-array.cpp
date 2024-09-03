

struct Node {
    Node *links[2];
    
    bool containsKey(int ind) {
        return (links[ind] != NULL);
    }

    Node *get(int ind) {
        return links[ind];
    }

    void put(int ind, Node *node) {
        links[ind] = node;
    }
};

class Solution {
private:
    Node *root;

public:
    Solution() {
        root = new Node();
    }

    void insert(int num) {
        Node *node = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int findMax(int num) {
        Node *node = root;
        int maxNum = 0;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(node->containsKey(!bit)) {
                maxNum = maxNum ^ (1 << i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxNum;
    }

    // Now, maximizeXor is part of the Solution class
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0); 

        // Vector to store offline queries
        vector<pair<int, pair<int, int>>> offlineQueries;

        // Sort the array of numbers
        sort(nums.begin(), nums.end()); 

        int index = 0;

        // Convert queries to offline queries and store them in a vector
        for(auto &it: queries) {
            offlineQueries.push_back({it[1], {it[0], index++}});
        }

        // Sort offline queries based on their end points
        sort(offlineQueries.begin(), offlineQueries.end());

        // Pointer to iterate through the array of numbers
        int i = 0; 

        // Number of elements in the array
        int n = nums.size(); 

        // Process each offline query
        for(auto &it : offlineQueries) {
            // Insert numbers into the trie until the current query's end point
            while(i < n && nums[i] <= it.first) {
                insert(nums[i]); 
                i++; 
            }

            // If there are numbers inserted into the trie, find the maximum XOR value for the query range
            if(i != 0) {
                ans[it.second.second] = findMax(it.second.first);
            } else {
                // If no numbers inserted, set result to -1
                ans[it.second.second] = -1; 
            }
        }

        // Return the results of all queries
        return ans;  
    }
};
