class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> time;
        for(int i=0;i<position.size();i++){
            time.push_back({position[i],speed[i]});
        }
        sort(time.rbegin(),time.rend());
        vector<double> st;
        for(auto it:time){
            st.push_back((double)(target-it.first)/it.second);
            while(st.size()>=2 && st.back() <= st[st.size()-2] ) st.pop_back();
        }
        return st.size();
    }
};