class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        if(s1.empty()) return true;

        unordered_map<char,int> orgFreq;
        unordered_map<char,int> windowFreq;

        for(auto s : s1){
            orgFreq[s]++;
        }

        int window = s1.size();
        int l = 0;
        int r = window-1;

        for(int i=l;i<=r;i++){
            windowFreq[s2[i]]++;
        }

        while(r<s2.size()){
            if(orgFreq==windowFreq) return true;

            windowFreq[s2[l]]--;

            if(windowFreq[s2[l]]==0){
                windowFreq.erase(s2[l]);
            }
            l++;
            r++;
            if(r<s2.size()){
                windowFreq[s2[r]]++;
            }
        }
        return false;
    }
};
