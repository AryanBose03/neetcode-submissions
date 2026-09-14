class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> hash;

        for(auto str : strs){
            string key = str;
            sort(key.begin(),key.end());
            hash[key].push_back(str);
        }
        for(auto &[key,anagrams]:hash)
            ans.push_back(anagrams);
        
        return ans;
    }
};
