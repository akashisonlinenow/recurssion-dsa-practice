class Solution {

private:
    void f(int ind, int n, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans){
        ans.push_back(ds);
        
        for(int i=ind;i<n;i++){
            
            // for non picking step
            if(i != ind && nums[i]==nums[i-1]) continue;


            // for pick step
            ds.push_back(nums[i]);
            f(i+1,n,ds,nums,ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // refer striver
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        f(0,n,ds,nums,ans);
        return ans;
    }
};