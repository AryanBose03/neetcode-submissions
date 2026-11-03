class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;

        for(auto num : nums)
            hashSet.insert(num);
        
        int maxCount = 0;
        for(auto num : hashSet){
            int count = 1;
            if(hashSet.find(num-1)!=hashSet.end())
                continue;
            else{
                while(hashSet.find(num+count)!=hashSet.end()){
                    count++;
                }
            }
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
};
