class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),ctr=1,k=0,lastPos=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[lastPos]) {
                ctr++;
                if(ctr>2) k++,nums[i]=1e9;
            }
            else ctr=1,lastPos=i;
        }
        sort(nums.begin(),nums.end());
        return n-k;
    }
};