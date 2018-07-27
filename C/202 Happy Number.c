/**
 * Set "sum_of_square(n)" operation can get the sum of square of each bit of n.
 *
 * If positive integer n has m bits, then the maximum of sum_of_square(n) is (9^2 * m) = 81m.
 * 
 * case 1: m >= 4
 * If m >= 4, then sum_of_square(n) will always less than n, 
 * which means: 
 * "if n >= 1000, after multiple times of sum_of_square(n), n will become 3-bit number or less."
 * 
 * case 2: m = 3
 * We find the the max sum_of_square(n) continuously.
 * n <= 999, take n = 999, sum_of_square(n) = 243.
 * n <= 243, take n = 199, sum_of_square(n) = 163.
 * n <= 163, take n = 159, sum_of_square(n) = 107.
 * n <= 107, take n = 107, sum_of_square(n) =  50.
 * It means, if n is a 3-bit number, 
 * after 1st operation, n is less than or equal to 243,
 * after 2nd operation, n is less than or equal to 163,
 * ...
 * after 4th operation, n is less than or equal to  50.
 * Thus, we can know:
 * "if n is a 3-bit number, after at most 4 times of sum_of_square(n), n will become a 2-bit number."
 * 
 * case 3: m <= 2
 * By definition, if n is a Happy Number, n will finally become 1 after multiple times of sum_of_square(n),
 * but if n is not a Happy Number, after the method of exhaustion, the result of sum_of_square(n) will finally get into a cycle:
 * 4, 16, 37, 58, 89, 145, 42, 20, 4, ...
 * 
 * 
 * By cases above, we can know that for positive integer n, there are only 2 condtions:
 * 1. n is a Happy Number: n become 1 after multiple times of sum_of_square(n)
 * 2. n is not a Happy Number: n get into a cycle contains 4 after multiple times of sum_of_square(n).
 * and the two condtions are mutual exclusive.
 * So, after multiple times of operation, if encounter 1 then return true, if encounter 4 return false.
 */

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
