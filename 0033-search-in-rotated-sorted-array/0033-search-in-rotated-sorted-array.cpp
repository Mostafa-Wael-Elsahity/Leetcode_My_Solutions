class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int,int>s;
        int n=nums.size();
        for(int i=0;i<n;i++) s[nums[i]]=i+1;
        return s[target]?s[target]-1:-1;
    }
};