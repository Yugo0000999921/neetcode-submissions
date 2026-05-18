class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& kv : mp) {
            int num = kv.first;
            int frequency = kv.second;
            buckets[frequency].push_back(num);
        }
        vector<int> res;
        res.reserve(k);
        
        for (int f = buckets.size() - 1; f >= 0 && res.size() < k; --f) {
            for (int num : buckets[f]) {
                res.push_back(num);
                if (res.size() == k) {
                    break;
                }
            }
        }

        return res;
    }
};