class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map <char,int> Map;
        for(int i=0;i<s.length();i++){
            Map[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(Map.find(t[i])!=Map.end()){
                Map[t[i]]-=1;
            }
            else
                return false;
        }
        for(auto items: Map){
            if(items.second != 0)
                return false;
            else
                return true;
        }
        
    }
};
