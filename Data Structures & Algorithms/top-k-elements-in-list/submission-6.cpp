class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        vector<int> ans;
        priority_queue<pair<int,int>> pq;

        for(auto num:nums){
            hash[num]++;
        }
        for(auto it:hash){
            pq.push({it.second,it.first});
        }
        for(int i=0;i<k;i++){
            auto [freq,res] = pq.top();
            ans.push_back(res);
            pq.pop();
        }
        return ans;
    }
};
