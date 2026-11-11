class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> ans (temperatures.size(),0);

        for(int i=0;i<temperatures.size();i++){
            if(st.empty()){
                st.push({temperatures[i],i});
            }
            else{
                while(!st.empty() && st.top().first<temperatures[i]){
                    int temp = st.top().first;
                    int ind = st.top().second;
                    st.pop();

                    ans[ind]=i-ind;
                }
                st.push({temperatures[i],i});
            }
        }
        return ans;
    }
};
