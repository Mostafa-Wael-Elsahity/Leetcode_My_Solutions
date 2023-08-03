class Solution {
public:
     vector<string> result;
    map<int, string> m;
    void solve(string digits, int k, string res){
        int n = digits.size();
        if(k >= n){
            result.push_back(res);
            return;
        }

        for(char ch:m[digits[k]]){
            solve(digits, k+1, res+ch);
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) return {};
        m.insert({'2', "abc"});
        m.insert({'3', "def"});
        m.insert({'4', "ghi"});
        m.insert({'5', "jkl"});
        m.insert({'6', "mno"});
        m.insert({'7', "pqrs"});
        m.insert({'8', "tuv"});
        m.insert({'9', "wxyz"});
        solve( digits, 0 , "");
        return result;
    }
};