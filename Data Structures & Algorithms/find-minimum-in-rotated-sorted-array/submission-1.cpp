class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return min(nums[0],nums[1]);
        }


        int low = 0;
        int high = nums.size()-1;

        if(nums[low] < nums[high]){
            return nums[low];
        }

        while(low <= high){
            int mid = low + (high-low)/2;

            if(mid > 0 && mid < nums.size()-1){
                if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]){
                    return nums[mid];
                }
                else if(nums[mid] > nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid - 1;
                }
            }
            else if(mid == 0){
                if(nums[mid] < nums[mid+1]){
                    return nums[mid];
                } else {
                    low = mid + 1;
                }
            }
            else {
                if(nums[mid] < nums[mid-1]){
                    return nums[mid];
                } else {
                    high = mid - 1;
                }
            }
            


        }
        return -1;
    }
};
