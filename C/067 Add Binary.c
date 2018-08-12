char* addBinary(char* a, char* b) {   
    int la = strlen(a), lb = strlen(b);
    char carry = 0;
    int len = (la > lb) ? la : lb;
    char *sum = (char *)calloc(len + 1, sizeof(char));
    sum[len] = '\0';
    memset(sum, '0', len);
    len--;
    
    while (len >= 0) {
        carry += (la > 0 ? a[--la] - '0' : 0 ) + (lb > 0 ? b[--lb] - '0' : 0);
        sum[len] = carry % 2 + '0';
        carry /= 2;
        len--;
    }

    char* str;
    if (carry) {
        char *str = (char *)calloc(len + 2, sizeof(char));
        memset(str, '1', 1);
        strcat(str, sum);
        return str;
    }
    
    return sum;
}
