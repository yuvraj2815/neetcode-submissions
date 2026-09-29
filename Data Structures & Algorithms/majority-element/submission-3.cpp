class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==0 && nums[0]==nums[1])return nums[0];
        sort(nums.begin(),nums.end());
        int mid=nums.size()/2;
        if(nums[mid]==nums[mid-1] || nums[mid]==nums[mid+1]) return nums[mid];
        return 0;
    }
};