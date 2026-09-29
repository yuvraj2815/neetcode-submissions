class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums);              // copy constructor
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};