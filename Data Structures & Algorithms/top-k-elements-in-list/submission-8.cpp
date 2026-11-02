class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       vector<int> res;
       priority_queue<pair<int,int>> pq;
       unordered_map<int,int> hash;

       for(auto num : nums)
            hash[num]++;

       for(auto it: hash){
            pq.push({it.second,it.first});
       }
       for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
       }
       return res;
    }
};
