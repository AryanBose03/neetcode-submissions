class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        int maxCount = 0;

        for(int i=0;i<nums.size();i++){
            hashSet.insert(nums[i]);
        }
        for(auto num : hashSet){
            int count = 1;
            
            if(hashSet.find(num-1)!=hashSet.end())
                continue;
            while(hashSet.find(num+count)!=hashSet.end()){
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
