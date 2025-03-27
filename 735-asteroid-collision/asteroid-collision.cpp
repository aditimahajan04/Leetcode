class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        list<int> st; // Changed from stack to list

        for (int i = 0; i < n; i++) { // Loop should be till n, not n-1
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }
            else {
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }
                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back();
                }
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                }
            }
        }

        // Convert list to vector
        vector<int> result(st.begin(), st.end());
        return result;
    }
};
