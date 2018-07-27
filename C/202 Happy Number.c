int sum_of_square(int n) {
    int NewNumber = 0;

    while (n != 0) {
        NewNumber += (n % 10) * (n % 10);
        n /= 10;
    }

    return NewNumber;
}

bool isHappy(int n) {
    while (1) {
        if (n == 1) return true;
        if (n == 4) return false;

        n = sum_of_square(n);
    }
}