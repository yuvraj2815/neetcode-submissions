class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (auto &it : asteroids) {
            bool destroyed = false;

            while (!st.empty() && it < 0 && st.top() > 0) {
                int top = st.top();

                if (top < abs(it)) {
                    st.pop();
                }
                else if (top == abs(it)) {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(it);
            }
        }

        vector<int> res;

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};