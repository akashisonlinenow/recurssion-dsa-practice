class Solution
{

private:
    void f(int ind, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (ind == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }

        // pick up the element
        if (arr[ind] <= target)
        {
            ds.push_back(arr[ind]);
            f(ind, arr, target - arr[ind], ans, ds);
            ds.pop_back(); // popping out to non pick the element
        }

        // non pick the element
        f(ind + 1, arr, target, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0, candidates, target, ans, ds);
        return ans;
    }
};