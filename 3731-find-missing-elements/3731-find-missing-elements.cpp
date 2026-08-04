class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < min)
            min = nums[i];

            if(nums[i] > max)
            max = nums[i];
        }

        for(int i = min + 1; i < max ; i++){
            bool found = false;
            for(int j = 0; j< nums.size(); j++){
                if(nums[j]== i){
                    found = true;
                    break;
                }
            }
            if (!found){
                ans.push_back(i);
            }
        }
        return ans;
    }
};