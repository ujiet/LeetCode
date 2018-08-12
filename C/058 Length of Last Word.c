int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int count = 0;
    
    while (s[len - 1] == ' ')
        len--;
    
    if (len == 0)
        return 0;
    
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == ' ')
            return count;
        else
            count++;
    }
    
    return count;
}
