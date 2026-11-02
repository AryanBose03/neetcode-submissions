class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(auto num : nums){
            if(hash.find(num)!=hash.end())
                return true;
            hash[num]++;
        }
        return false;
    }
};