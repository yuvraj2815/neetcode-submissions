class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(auto &it : tokens){
            if(it!="+" && it!="-" && it!="*" && it!="/"){
                st.push(stoi(it));
            }
            else if(it =="+"){
                int top=st.top();
                st.pop();
                int input=st.top()+top;
                st.pop();
                st.push(input);
            }
            else if(it=="*"){
                int top=st.top();
                st.pop();
                int input=st.top()*top;
                st.pop();
                st.push(input);
            }
            else if(it=="-"){
                int top=st.top();
                st.pop();
                int input=st.top()-top;
                st.pop();
                st.push(input);
            }else{
                int top=st.top();
                st.pop();
                int input=st.top()/top;
                st.pop();
                st.push(input);
            }
        }
        return st.top();
    }
};
