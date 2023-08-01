class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int lim=1<<n;
        vector<vector<int>>ans;
        for(int i=1;i<lim;i++)
            if(__builtin_popcount(i)==k){
                vector<int>con;
                for(int j=0;j<n;j++)
                    if(i&(1<<j)) 
                        con.push_back(j+1);
                ans.push_back(con);
            }
        return ans;
    }
};