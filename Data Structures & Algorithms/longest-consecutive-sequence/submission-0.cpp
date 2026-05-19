class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest_streak = 0;
        for (int num : num_set) {
            // num - 1 がセット内に存在しない場合、これが数列の「始点」となる
            if (!num_set.count(num - 1)) {
                int current_num = num;
                int current_streak = 1;

                // 連続する次の数字が存在する限りカウントアップ
                while (num_set.count(current_num + 1)) {
                    current_num += 1;
                    current_streak += 1;
                }

                // 最大の連続数を更新
                longest_streak = max(longest_streak, current_streak);
            }
        }

        return longest_streak;
    }
};
