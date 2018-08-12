void swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
    
    return;
}

int thirdMax(int* nums, int numsSize) {
    long long max1, max2, max3;
    
    max1 = max2 = max3 = LLONG_MIN;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= max3 || nums[i] == max2 || nums[i] == max1) continue;
        
        max3 = nums[i];
        if (max3 > max2) swap(&max3, &max2);
        if (max2 > max1) swap(&max2, &max1);
    }
    
    return (max3 == LLONG_MIN) ? (int) max1 : (int) max3;
}
