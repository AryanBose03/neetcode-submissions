class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int maxi = 0;
        unordered_map<char,int> hashMap;

        while(j<s.size()){
            if(hashMap.find(s[j])==hashMap.end()){
                maxi = max(maxi,j-i+1);
                hashMap[s[j]]++;
                j++;
            }
            else{
                hashMap.erase(s[i]);
                i++;
            }
            
        }
        return maxi;
    }
};
