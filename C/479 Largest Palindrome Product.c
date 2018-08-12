long long createPalin(long long firstHalf, int n) {
    long long reverse = 0;
    long long temp = firstHalf;
    
    while (temp) {
        reverse = 10*reverse + temp % 10;
        temp /= 10;
    }
    
    return firstHalf*(long long )pow(10, n) + reverse;
}

int largestPalindrome(int n) {
    if (n == 1)
        return 9;
    
    long long upperBound = pow(10, n) - 1, lowerBound = pow(10, n - 1);
    long long maxNumber = upperBound*upperBound;
    
    long long firstHalf = maxNumber / (long long ) pow(10, n);
    
    int findMaxPalin = 0;
    long long palin;
    
    while (!findMaxPalin) {
        palin = createPalin(firstHalf, n);
        
        long long i = upperBound;
        while (i >= lowerBound) {
            if (palin / i > maxNumber || i * i < palin)
                break;
            
            if (palin % i == 0) {
                printf("palin = %lld\n", palin);
                printf("i = %lld\n", i);
                printf("palin / i = %lld\n", palin / i);
                
                findMaxPalin = 1;
                break;
            }
            i--;
        }
        firstHalf--;
    }
    
    return (int ) (palin % 1337);
}
