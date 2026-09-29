class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> res;
        for(auto const &s:strs){
            string SortedS=s;
            sort(SortedS.begin(),SortedS.end());
            res[SortedS].push_back(s);
        }

        vector<vector<string>> result;
        for(auto &ans:res){
            result.push_back(ans.second);
        }
        return result;
    }
};
