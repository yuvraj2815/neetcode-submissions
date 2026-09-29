class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        vector <int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[k++]=nums[i];
            }
        }
        return k;
    }
};