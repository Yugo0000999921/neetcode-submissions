class Solution {
public:
    bool isPalindrome(string s) {
        string tmp = "";
        for(char c:s){
            if(isalnum(c)) tmp.push_back(tolower(c));
        }
        string rev = tmp;
        reverse(rev.begin(),rev.end());

        return tmp == rev;
    }
};
