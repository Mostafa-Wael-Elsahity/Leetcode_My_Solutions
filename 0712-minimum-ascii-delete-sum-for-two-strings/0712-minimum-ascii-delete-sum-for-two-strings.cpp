class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size(),memo[n+5][m+5];
        memset(memo,-1,sizeof memo);
        function<int(int,int)> dp=[&](int i,int j)->int{
            if(i==n) {
                int sum=0;
                while(j<m) sum+=s2[j++];
                return sum;
            }
            if(j==m){
                int sum=0;
                while(i<n) sum+=s1[i++];
                return sum;
            }
            int &res=memo[i][j];
            if(~res) return res;
            res=1e9;
            if(s1[i]==s2[j]) res=dp(i+1,j+1);
            return res=min({res,dp(i+1,j)+s1[i],dp(i,j+1)+s2[j]});
        };
        return dp(0,0);
    }
};