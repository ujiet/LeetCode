int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    /* rSize is var for manipulating */
    int *arr;
    int rSize = *returnSize = digitsSize;
    int count = 0;
    
    /* counting how many 9s are there in the last digits */
    for (int i = 0; i < rSize; i++) {
        if (digits[i] == 9)
            count++;
        else count = 0;
    }        
    
    /**
     *  if all 9, then the new number is 10.....0, or it should be like maybe 123450...0, 
     *  the number of 0s depends on the count, so we just need to memcpy (numsSize - count) numbers. 
     */
    if (count == rSize) {
        *returnSize = ++rSize;
        arr = (int *)calloc(rSize, sizeof(int));
        
        arr[0] = 1;
    } else {
        rSize = rSize - count;
        arr = (int *)calloc(digitsSize, sizeof(int));
        memcpy(arr, digits, rSize*sizeof(int));
        
        arr[rSize - 1]++;
    }
    
    return arr;
}
