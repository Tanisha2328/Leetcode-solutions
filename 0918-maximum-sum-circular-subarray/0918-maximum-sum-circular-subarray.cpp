class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int min_ending = nums[0];  
      int max_ending = nums[0]; 
      int ans = nums[0];
      int min_sum = nums[0];
      int sum = 0;
      for ( int i = 0; i < nums.size() ; i++){
        sum += nums[i]; 
      }
      for ( int i = 1; i < nums.size() ; i++){
        max_ending = max( max_ending + nums[i] , nums[i]);
        min_ending = min( min_ending + nums[i] , nums[i]);
        ans = max(ans , max_ending);
        min_sum = min(min_sum , min_ending);
      } 
      if (ans < 0){
        return ans;
      }
      int ans1 = sum - min_sum;
      ans = max(ans , ans1);

      return ans;
    }
};