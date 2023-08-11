class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int memo[101][101][101]={};
        function<int(int,int,int)> dp=[&](int l,int r,int k)->int{
            if(l>r) return 0;
            int &res=memo[l][r][k],ll=l,kk=k;
            if(res) return res;
            while(l+1<=r&&boxes[l]==boxes[l+1]) l++,k++;
            int ans=(k+1)*(k+1)+dp(l+1,r,0);
            for(int m=l+1;m<=r;m++)
                if(boxes[m]==boxes[l])
                    ans=max(ans,dp(m,r,k+1)+dp(l+1,m-1,0));
            return memo[ll][r][kk]=ans;
        };
        return dp(0,boxes.size()-1,0);
    }
};