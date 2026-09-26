class Solution {
public:
    int indxMin(vector<int>& nums){
        int start = 0;
        int end = nums.size() - 1;

        while(start < end){
            int mid = start + (end - start)/2;

            if(nums[mid] > nums[end]){
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return start;
    }
    int binary(vector<int>& nums, int target,int start, int end){
        

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = indxMin(nums);

        if(pivot == 0){
            return binary(nums,target,0,n-1);
        }

        int ans = binary(nums,target,0,pivot-1);
        if(ans != -1){
            return ans;
        }
        return binary(nums,target,pivot,n-1);
    }
};
