
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() || s.empty() || t.size()>s.size())
            return "";

        unordered_map<char,int> hashMap;

        for(auto ch : t){
            hashMap[ch]++;
        }

        int required = t.size();
        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int r=0;r<s.size();r++){
            if(hashMap.find(s[r])!=hashMap.end()){
                if(hashMap[s[r]]>0)
                    required--;

                hashMap[s[r]]--;
            }

            while(required==0){
                if(r-l+1<minLen){
                    minLen = r-l+1;
                    start = l;
                }

                if(hashMap.find(s[l])!=hashMap.end()){
                    hashMap[s[l]]++;

                    if(hashMap[s[l]]>0)
                        required++;
                }

                l++;
            }
        }

        if(minLen==INT_MAX)
            return "";

        return s.substr(start,minLen);
    }
};
