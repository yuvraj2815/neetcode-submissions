class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber>0){
            columnNumber -=1;
            int extra=columnNumber%26;
            res +=('A'+extra);
            columnNumber=columnNumber/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};