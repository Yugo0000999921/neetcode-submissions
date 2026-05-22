class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int len = s1.size();

    // s1のカウント
        unordered_map<char,int> mps1;
        for (char c : s1) mps1[c]++;  

    // 最初のウィンドウ
        unordered_map<char,int> mps2;
        for (int i = 0; i < len; i++) mps2[s2[i]]++;
        if (mps1 == mps2) return true;
        

        for (int i = len; i < s2.size(); i++) {
            mps2[s2[i]]++;           // 右を追加
            mps2[s2[i-len]]--;       // 左を削除
            if (mps2[s2[i-len]] == 0)
                mps2.erase(s2[i-len]); 
            if (mps1 == mps2) return true;
            }
        return false;
        }
    };

