class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> st;
        int res=0;
        for(auto &it : operations){
            if(it=="+"){
                int top=st.top();
                st.pop();
                int newEnt= top+st.top();
                st.push(top);
                st.push(newEnt);
                res+=newEnt;
            }
            else if(it=="C"){
                res-=st.top();
                st.pop();
            }
            else if(it=="D"){
                int newEnt=st.top()*2;
                st.push(newEnt);
                res+=newEnt;
            }else{
                st.push(stoi(it));
                res +=st.top();
            }
        }
        return res;
    }
};