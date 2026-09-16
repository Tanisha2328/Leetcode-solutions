class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    int left = 0 ;
    int right ;
    int sum = 0;
    for ( int i = 0; i < nums.size(); i++){
        sum += nums[i];
    }
    for (int i = 0; i < nums.size(); i++){
        right = sum - left - nums[i];
        if ( left == right){
            return i;
        }
         left += nums[i];
    }
    return -1;
    }
};