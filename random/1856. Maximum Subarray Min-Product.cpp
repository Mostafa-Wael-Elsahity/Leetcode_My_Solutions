class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long long n=nums.size(),res=0;
        int const mod=1e9+7;
        vector<long long>prefixSum(n+1);
        for(int i=1;i<=n;i++) prefixSum[i]=prefixSum[i-1]+nums[i-1];
        vector<pair<int,long long>>st;
        for(int i=0;i<n;i++){
            int newStart=i;
            while(!st.empty()&&st.back().second>nums[i]) {
                int start=st.back().first;
                long long val=st.back().second;
                st.pop_back();
                long long total= prefixSum[i]-prefixSum[start];
                res=max(res,total*val);
                newStart=start;
            }
            st.push_back({newStart,nums[i]});
        }
        for(int i=0;i<st.size();i++){
            long long total=prefixSum[n]-prefixSum[st[i].first];
            res=max(res,total*st[i].second);
        }
        return res%mod;
    }
};
