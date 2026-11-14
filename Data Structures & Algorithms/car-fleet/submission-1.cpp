class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> combination;

        for(int i=0;i<position.size();i++){
            combination.push_back({position[i],speed[i]});
        }
        sort(combination.rbegin(),combination.rend());
        stack<int> st;
        double currentFleet = -1;

        for(int i=0;i<combination.size();i++){
            if(i==0){
                currentFleet = (double)(target-combination[i].first)/combination[i].second;
                st.push(combination[i].first);
                continue;
            }
            if(((double)target-combination[i].first)/combination[i].second>currentFleet){
                st.push(combination[i].first);
                currentFleet = (double)(target-combination[i].first)/combination[i].second;
            }
        }
        return st.size();
    }
};
