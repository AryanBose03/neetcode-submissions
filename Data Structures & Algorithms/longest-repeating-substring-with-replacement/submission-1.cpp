class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxFreq = 0, maxLen = 0;
        unordered_map<char,int> hashMap;

        while(r<s.size()){
            hashMap[s[r]]++;
            maxFreq = max(maxFreq, hashMap[s[r]]);
            if((r-l+1) - maxFreq>k){
                hashMap[s[l]]--;
                l++;
            }
            else if((r-l+1)-maxFreq<=k){
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};
