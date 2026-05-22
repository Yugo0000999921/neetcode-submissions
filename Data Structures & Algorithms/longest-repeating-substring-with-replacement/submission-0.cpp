class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        // sののユニークな要素をunordered_setで記録
        unordered_set<char> st(s.begin(),s.end());
        // 考え:cでどれだけ長い部分文字列を作成できるか,というのをO(n)で探索したい
        for(char c : st){
            // 文字数
            int count = 0;
            int left = 0;
            for(int right = 0;right < s.size();right++){
                if(s[right] == c){
                    count ++;
                }
                // shrink
                while((right-left+1)-count > k){
                    if(s[left]==c){
                        count --;
                    }
                    left ++;
                }
                res = max(res,right-left+1);
            }
        }
        return res;
    }
};
