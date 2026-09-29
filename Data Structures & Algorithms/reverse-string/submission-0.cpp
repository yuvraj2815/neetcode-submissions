class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> stk;
        for (char& c : s) {
            stk.push(c);
        }
        int i = 0;
        while (!stk.empty()) {
            s[i++] = stk.top();
            stk.pop();
        }
    }
};