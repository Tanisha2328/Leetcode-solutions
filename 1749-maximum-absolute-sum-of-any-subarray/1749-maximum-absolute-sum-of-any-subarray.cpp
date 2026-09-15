class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
    int min_ending = nums[0];
    int max_ending = nums[0];
    int ans = abs(nums[0]);
    for ( int i = 1; i < nums.size(); i++){
        min_ending = min(min_ending + nums[i] , nums[i]);
        max_ending = max(max_ending + nums[i] , nums[i]);
        ans = max (ans , max(abs(min_ending) , abs(max_ending)));
    }
    return ans;
    }
};