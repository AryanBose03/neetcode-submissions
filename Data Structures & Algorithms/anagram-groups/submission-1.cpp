class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> res;
       unordered_map<string,vector<string>> hash;

       for(auto str : strs){
            string copyStr = str;
            sort(copyStr.begin(),copyStr.end());
            
            hash[copyStr].push_back(str);
       }
       for(auto it : hash){
            res.push_back(it.second);
       }
       return res;
    }
};
