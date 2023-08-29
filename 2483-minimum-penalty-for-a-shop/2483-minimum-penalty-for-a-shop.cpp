class Solution {
public:
    int bestClosingTime(string customers) {
        int ctr=0,ans=1e9,n=customers.size();
        vector<int> prefix(n+5);
        for(int i=0;i<n;i++) prefix[i+1]+=prefix[i]+(customers[i]=='Y');
        for(int i=0;i<=n;i++) 
            if(ans>prefix[n]-prefix[i]+i-prefix[i]) 
                ans=prefix[n]-prefix[i]+i-prefix[i],ctr=i;
        return ctr;
    }
};