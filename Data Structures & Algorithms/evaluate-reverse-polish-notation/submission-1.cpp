class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int ans = 0;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/")
                st.push(tokens[i]);
            else{
                string x, y;
                int res;
                if(!st.empty()){
                    x = st.top();
                    st.pop();
                }
                if(!st.empty()){
                    y = st.top();
                    st.pop();
                }
                if(tokens[i]=="+"){
                    res = stoi(x) + stoi(y);
                }
                else if(tokens[i]=="-"){
                    res = stoi(y) - stoi(x);
                }
                else if(tokens[i]=="*"){
                    res = stoi(x) * stoi(y);
                }
                else
                    res = stoi(y)/stoi(x);
                st.push(to_string(res));
            }
        }
        if(!st.empty()){
            string res = st.top();
            ans = stoi(res);
        }
        return ans;
    }
};
