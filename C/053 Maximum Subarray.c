int maxSubArray(int* nums, int numsSize) {
    int r[numsSize];
    int max = nums[0];
    
    r[0] = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        r[i] = (r[i-1] + nums[i] >= nums[i])? r[i-1] + nums[i] : nums[i];
        max = (max >= r[i])? max : r[i];
    }
    
    return max;
}
