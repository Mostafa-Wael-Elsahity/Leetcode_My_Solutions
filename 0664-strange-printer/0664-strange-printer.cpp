class Solution {
public:
    int strangePrinter(string s) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int n=s.size();
        string str; // to compression s
        for(int i=0; i<n;){
            char ch = s[i];
            while(i<n && ch==s[i]) i++;
            str.push_back(ch);
        }
        s=str;
        vector<vector<int>>memo(101,vector<int>(101,-1));
        function<int(int,int)> dp=[&](int l,int r)->int{
            if(l>r) return 0;
            int &res=memo[l][r];
            if(~res) return res;
            res=1+dp(l+1,r);
            for(int i=l+1;i<=r;i++)
                if(s[i]==s[l])
                    res=min(res,dp(i,r)+dp(l+1,i-1));
            return res;
        };
        return dp(0,s.size()-1);
    }
};