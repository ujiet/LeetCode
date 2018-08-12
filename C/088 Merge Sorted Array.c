void merge(int* nums1, int m, int* nums2, int n) {
    int l1 = m - 1, l2 = n - 1;
    int index = m + n - 1;
    
    while (l1 >= 0 && l2 >= 0) 
        if (nums1[l1] > nums2[l2]) 
            nums1[index--] = nums1[l1--];
        else 
            nums1[index--] = nums2[l2--];
    
    if (l2 >= 0) 
        for (int i = 0; i <= l2; i++) 
            nums1[i] = nums2[i];
    
    return;
}
