class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size(),memo[n+5][n+5];
        memset(memo,-1,sizeof memo);
        function<int(int,int)> dp=[&](int l,int r)->int{
            int &res=memo[l][r];
            if(~res) return res;
            res=n;
            int pos=-1;
            for(int i=l;i<r;i++){
                if(s[i]!=s[r]&&pos==-1) pos=i;
                if(~pos) res=min(res,1+dp(pos,i)+dp(i+1,r));
            }
            if(pos==-1) res=0;
            return res;
        };
        return dp(0,n-1)+1;
    }
};