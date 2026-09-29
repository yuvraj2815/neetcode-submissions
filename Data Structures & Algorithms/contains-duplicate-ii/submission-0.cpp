class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int,int> dup;
        for(int i=0;i<nums.size();i++){
            if(dup.find(nums[i])!=dup.end()){
                if(i-dup[nums[i]] <=k) return true;
            }
            dup[nums[i]]=i;
        }
        return false;
    }
};