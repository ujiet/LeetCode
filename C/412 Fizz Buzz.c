char** fizzBuzz(int n, int* returnSize) {
    char **res = (char **) malloc(n * sizeof(char *));
    *returnSize = n;
    
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 15 == 0) {
            res[i] = (char *) malloc(9 * sizeof(char));
            sprintf(res[i], "%s", "FizzBuzz");
        } else if ((i + 1) % 3 == 0) {
            res[i] = (char *) malloc(5 * sizeof(char));
            sprintf(res[i], "%s", "Fizz");
        } else if ((i + 1) % 5 == 0) {
            res[i] = (char *) malloc(5 * sizeof(char));
            sprintf(res[i], "%s", "Buzz");          
        } else {
            res[i] = (char *) malloc(11 * sizeof(char));
            sprintf(res[i], "%d", i + 1);        
        }
    }
    
    return res;
}
