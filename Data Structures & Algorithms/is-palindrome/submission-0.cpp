class Solution {
public:
    bool checkalphanum(char c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            return true;
        }
        return false;
    }

    char toLower(char c){
        if(c >= 'A' && c <= 'Z'){
            return c - 'A' + 'a';
        }
        return c;
    }

    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            while (i <= j && !checkalphanum(s[i])) i++;
            while (i <= j && !checkalphanum(s[j])) j--;
            if (i > j) break; 

            if (toLower(s[i]) != toLower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};