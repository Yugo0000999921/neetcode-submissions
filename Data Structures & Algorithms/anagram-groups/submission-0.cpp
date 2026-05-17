class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        groups.reserve(2 * strs.size());

        for (const string& s : strs) { 
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(groups.size());
        
        for (auto& kv : groups) {
            res.push_back(move(kv.second)); 
        }
        return res;
    }
};