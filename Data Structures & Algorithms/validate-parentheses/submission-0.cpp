class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto &it : s) {
            if (it == ')') {
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }
            else if (it == '}') {
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
            }
            else if (it == ']') {
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }
            else {
                st.push(it);
            }
        }

        return st.empty();
    }
};