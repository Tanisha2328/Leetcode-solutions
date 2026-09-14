class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_ending = nums[0];
        int max_ending = nums[0];
        int ans = nums[0];
        for (int i = 1 ; i < nums.size(); i++){
            int v1 = nums[i];
            int v2 = nums[i] * min_ending;
            int v3 = nums[i] * max_ending;
            min_ending = min(v1 , min(v2, v3));
            max_ending = max(v1 , max(v2, v3));
            ans = max(ans , max(min_ending , max_ending));
        }
        return ans;
    }
};