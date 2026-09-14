class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto num : nums){
            hash[num]++;
        }
        for(auto it : hash){
            if(it.second>1)
                return true;
        }
        return false;
    }
};