class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // 1. Make a copy of the original array
        vector<int> ans = nums; 
        
        // 2. Insert the elements of nums at the end of ans
        ans.insert(ans.end(), nums.begin(), nums.end());
        
        return ans;
    }
};