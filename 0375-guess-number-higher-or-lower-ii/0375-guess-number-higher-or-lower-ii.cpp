class Solution {
public:
    int getMoneyAmount(int n) {
        int memo[n+5][n+5];
        memset(memo,-1,sizeof memo);
        function<int(int,int)>solve=[&](int left,int right)->int{
            if(left>=right) return 0;
            int &res=memo[left][right];
            if(~res) return res;
            res=1e6;
            for(int i=left;i<=right;i++){
                res=min(res,i+max(solve(left,i-1),solve(i+1,right)));
            }
            return res;
        };
        return solve(1,n);
    }
};