class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                } else {
                    int up = 0;
                    int left = 0;
                    
                    if (i > 0) {
                        up = prev[j];
                    } else {
                        up = 0;
                    }

                    if (j > 0) {
                        left = temp[j - 1];
                    } else {
                        left = 0;
                    }

                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};
