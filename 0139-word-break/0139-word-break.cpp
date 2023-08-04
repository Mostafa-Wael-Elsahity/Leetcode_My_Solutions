class Solution {
public:
    set<string>word;
    string ss;
    int len;
    int memo[305][305];
    bool check(int st=0,int en=0){
        if(en==len)
            return en==st;
        int &res=memo[st][en];
        if(~res) return res;
        res=0;
        string x=ss.substr(st,en-st+1);
        if(word.find(x)!=word.end()) 
            res=check(en+1,en+1);
        res=res|check(st,en+1);
        return res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict) word.insert(i);
        ss=s,len=s.size();
        memset(memo,-1,sizeof memo);
        return check();
    }
};