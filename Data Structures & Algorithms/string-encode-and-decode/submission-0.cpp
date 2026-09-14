class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for(auto str : strs){
            encoded+=to_string(str.size());
            encoded+='#';
            encoded+=str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while(i<s.size()){
            int delimiter = i;
            while(delimiter<s.size() && s[delimiter]!='#'){
                delimiter++;
            }
            string len = s.substr(i,delimiter-i);
            int length = stoi(len);

            int start = delimiter + 1;
            res.push_back(s.substr(start,length));

            i = start + length;
        }
        return res;
    }
};
