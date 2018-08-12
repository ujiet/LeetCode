int** generate(int numRows, int** columnSizes) {
    int **result = (int **) malloc(numRows * sizeof(int *));
    *columnSizes = (int *) malloc(numRows * sizeof(int));
    
    for (int i = 0; i < numRows; i++) {
        (*columnSizes)[i] = i + 1;
        result[i] = (int *) malloc((i + 1) * sizeof(int));
        
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                result[i][j] = 1;
            else
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    return result;
}
