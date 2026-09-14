class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for(auto x: nums){
            int count = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==x){
                    count++;
                }
                if(count>1){
                    return true;
                }
            }
        }
    }
};
