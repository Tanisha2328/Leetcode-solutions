class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int best_ending = nums[0];
    int ans = nums[0];
    for(int i = 1; i < nums.size(); i++){
        int v1 = best_ending + nums[i];
        int v2 = nums[i];
        best_ending = max(v1, v2);
        ans = max(ans , best_ending);
    }
    return ans;
    }
};